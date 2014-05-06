/**
 * You shouldn't be reading this file, really. This is a (very) experimental approach
 * to implement dynamic policies.
 *
 * Sill here? 
 *
 * Still reading, really? Ok...
 * The idea being that using template function overload will not instantiate the overloads
 * if they are declared after the dispatch function.
 * This is why we delegate the algorithms to the policies themselves, so that the dispatcher
 * can force instantiation of the member algorithms (if defined), even if the type is declared
 * later in the code.
 *
 * In a nutshell, this file contains a bunch of meta helper classes to do things you really
 * shouldn't be doing. What we do is build up a typelist by appending each user declared policy.
 * A dispatcher function is instantiated for each algorithm. This is actually a template overload
 * taking a dynamic policy. If it is a built-in policy, we cast and forward it. If not, we
 * go through our typelist until we find the actual type and we invoke the right member
 * algorithm.
 *
 * The whole thing is crying for concepts and the dispatch is more than clumsy... Again,
 * this is a draft implementation...
 *
 */

#pragma once

// The structure of this is as follow:
// - first we declare a bunch of helper functions
// - then for each algo, we declare a dispatcher for each algorithm, this contains:
//   * a type trait: think of this as a concept, used to check if the method is defined
//   * a dispatch function, which actually calls the algorithm we are interested in
//   * a typedef for the return type, because I couldn't be bothered to implement this
//     as a type trait
// - immediately following the dispatcher is the dynamic policy template overload for the
//   given algo.

namespace std {
namespace experimental {
namespace parallel {

namespace details {

// The ugly guts
// *************

// counter facilities: this counts the number of instances of a template
typedef char (&no_tag)[1]; 
typedef char (&yes_tag)[2]; 

template< typename U > no_tag test(U);
template< typename T, long > struct instantiation_count; 
template< typename T, long value_ = 
          sizeof(decltype(test(static_cast<instantiation_count<T,0>*>(nullptr)))) +
          sizeof(decltype(test(static_cast<instantiation_count<T,1>*>(nullptr)))) +
          sizeof(decltype(test(static_cast<instantiation_count<T,2>*>(nullptr)))) +
          sizeof(decltype(test(static_cast<instantiation_count<T,3>*>(nullptr)))) +
          sizeof(decltype(test(static_cast<instantiation_count<T,4>*>(nullptr)))) +
          sizeof(decltype(test(static_cast<instantiation_count<T,5>*>(nullptr))))
> 
struct instantiation_count 
{ 
    static constexpr long value = value_ - 7 + 1;
    using _next_instantiation = instantiation_count<T, value>;
    template<typename U>
    friend yes_tag test(instantiation_count<U, value>*); 
}; 

// MTP algorithms

template <typename Key = std::experimental::parallel::execution_policy, 
          int N = instantiation_count<Key>::value>
struct PolicyRegistry { typedef void type; };


// Base case for type list scan. If there is no more type, the type was not
// an execution policy. This should in practice never happen since an dynamic 
// execution policy can only be constructed from a valid is_execution_policy type.
template< bool done = true >
struct for_each_t
{
  template< int N, typename Dispatcher, typename Key, typename ... Args>
  static auto execute(const Key &exec, Args ... args)
    -> typename Dispatcher::Return
  {
    throw std::invalid_argument("Invalid execution policy.");
  }
};

// This is the actual scan going though the typelist
template<>
struct for_each_t<false>
{
  /**
   * @brief Iterate through a typelist.
   * @tparam N current index in the typelist.
   * @tparam Dispatcher Method dispatcher to call if the type matches.
   * @param exec The dynamic execution policy object.
   * @param args Arguments to the dispatcher.
   */
  template< int N, typename Dispatcher, typename Key, typename ... Args>
  static auto execute(const Key &exec, Args ... args )
    -> // decltype auto, where are you?
       typename 
       /* result_of<
         decltype (&typename Dispatcher::template Dispatch<true>::dispatch)
           (typename Dispatcher::template Dispatch<true>,
            const typename PolicyRegistry<Key, N>::type&, Args...)
       >::type*/
       Dispatcher::Return
  {
    // The head of the typelist
    using _Type = typename PolicyRegistry<Key, N>::type;

    // Does the type supports the operation we need?
    using _is_supported = typename Dispatcher::template is_supported<_Type, Args...>;

    // if the type matches, we found the underlying type, undo type erasure and call dispatcher
    if(exec.type() == typeid(_Type)){
      const _Type & _ref = *exec.template get<_Type>();
      using _TrueDispatch = typename Dispatcher::template Dispatch<_is_supported::value>;
      return _TrueDispatch::dispatch(_ref, args ...);
    }
    // otherwise move to the next type
    else {
      using Next = typename PolicyRegistry<Key, N+1>::type;
      using ForEach = typename details::for_each_t< std::is_same<Next,void>::value >;
      ForEach::template execute<N+1, Dispatcher>(exec, args...);
    }
  }
};


template<typename Key, typename Dispatcher, typename ... Args>
inline void for_each_type(const Key &exec, Args ... args)
{
  using First = typename details::PolicyRegistry<Key, 0>::type;
  using ForEach = typename details::for_each_t< std::is_same<First,void>::value >;
  ForEach::template execute<0, Dispatcher>(exec, args...);
}

} // namespace details








// Algorithms definition
// *********************

namespace details {

/**
 * The sort dispatcher calls the sort member function if it exists, does nothing otherwise.
 */
struct SortDispatcher {
  using Return = void;

  template< bool valid = false >
  struct Dispatch {
    template<typename P, typename ... Args>
    static void dispatch(const P&, Args ...){
      throw std::invalid_argument("Invalid execution policy: the policy does not support sort");   
    }
  };

  // sfinae trait to check whether the target is supported
  template<typename T, typename ... Args>
  struct is_supported
  {
  private:
    typedef std::true_type yes;
    typedef std::false_type no;
   
    template<typename P, typename ... Is> 
    static auto test(int) -> decltype(std::declval<P>().template sort(std::declval<Is>()...), yes());
    template<typename P, typename ... Is> static no test(...);
   
  public:
    static constexpr bool value = std::is_same<decltype(test<T,Args...>(0)),yes>::value;
  };
};

template< >
struct SortDispatcher::Dispatch<true> {
  template<typename P, typename ... Args>
  static void dispatch(const P& p, Args ... args){
    p.sort(args...);
  }
};


} // namespace details

/**
 * @brief This is the actual dispatcher for the type erased policy.
 */
template<typename RandomIt>
void execution_policy::sort(RandomIt first, RandomIt last) const
{
  if(get<sequential_execution_policy>()){
    get<sequential_execution_policy>()->sort(first, last);
  }
  else if(get<parallel_execution_policy>()){
    get<parallel_execution_policy>()->sort(first, last);
  }
  else {
    // It is none of the basic policies, go though our type list and try to find its
    // true type
    details::for_each_type<execution_policy, details::SortDispatcher>(*this, first, last);
  }
}



}}}
