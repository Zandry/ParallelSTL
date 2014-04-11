#if not defined _EXPERIMENTAL_N3554_ALGORITHM and not defined _EXPERIMENTAL_N3554_UTILITY
#error Inlcude <parallel/algorithm> or <parallel/utility>
#endif

#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#define _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL

#include <algorithm>

namespace std {

namespace parallel {

namespace policy {

static struct seq {
  // Algorithm

  // non-modifying sequence operations:
  template<class InputIterator, class Predicate>
    bool all_of(InputIterator first, InputIterator last, Predicate pred);

  template<class InputIterator, class Predicate>
    bool any_of(InputIterator first, InputIterator last, Predicate pred);

  template<class InputIterator, class Predicate>
    bool none_of(InputIterator first, InputIterator last, Predicate pred);

  template<class InputIterator, class Function>
    Function for_each(InputIterator first, InputIterator last, Function f);

  template<class InputIterator, class Size, class Function>
    Function for_each_n(InputIterator first, Size n, Function f);

  template<class InputIterator, class T>
    InputIterator find(InputIterator first, InputIterator last, const T& value);

  template<class InputIterator, class Predicate>
    InputIterator find_if(InputIterator first, InputIterator last,
                          Predicate pred);

  template<class InputIterator, class Predicate>
    InputIterator find_if_not(InputIterator first, InputIterator last,
                              Predicate pred);

  template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1
      find_end(ForwardIterator1 first1, ForwardIterator1 last1,
               ForwardIterator2 first2, ForwardIterator2 last2);

  template<class ForwardIterator1, class ForwardIterator2,
           class BinaryPredicate>
    ForwardIterator1
      find_end(ForwardIterator1 first1, ForwardIterator1 last1,
               ForwardIterator2 first2, ForwardIterator2 last2,
               BinaryPredicate pred);

  template<class InputIterator, class ForwardIterator>
    InputIterator
      find_first_of(InputIterator first1, InputIterator last1,
                    ForwardIterator first2, ForwardIterator last2);

  template<class InputIterator, class ForwardIterator,
           class BinaryPredicate>
    InputIterator
      find_first_of(InputIterator first1, InputIterator last1,
                    ForwardIterator first2, ForwardIterator last2,
                    BinaryPredicate pred);

  template<class ForwardIterator>
    ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last);

  template<class ForwardIterator, class BinaryPredicate>
    ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last,
                                  BinaryPredicate pred);

  template<class InputIterator, class EqualityComparable>
    typename iterator_traits<InputIterator>::difference_type
      count(InputIterator first, InputIterator last, const EqualityComparable &value);

  template<class InputIterator, class Predicate>
    typename iterator_traits<InputIterator>::difference_type
      count_if(InputIterator first, InputIterator last, Predicate pred);

  template<class InputIterator1, class InputIterator2>
    pair<InputIterator1,InputIterator2>
      mismatch(InputIterator1 first1, InputIterator1 last1, 
               InputIterator2 first2);

  template<class InputIterator1, class InputIterator2, class BinaryPredicate>
    pair<InputIterator1,InputIterator2>
      mismatch(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, BinaryPredicate pred);

  template<class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2);

  template<class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, BinaryPredicate pred);

  template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                            ForwardIterator2 first2, ForwardIterator2 last2);

  template<class ForwardIterator1, class ForwardIterator2,
           class BinaryPredicate>
    ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                            ForwardIterator2 first2, ForwardIterator2 last2,
                            BinaryPredicate pred);


  template<class ForwardIterator, class Size, class T>
    ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count,
                             const T& value);

  template<class ForwardIterator, class Size, class T, class BinaryPredicate>
    ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count,
                             const T& value, BinaryPredicate pred);

  
  // modifying sequence operations:
  // copy:
  template<class InputIterator, class OutputIterator>
    OutputIterator copy(InputIterator first, InputIterator last,
                      OutputIterator result);

  template<class InputIterator, class Size, class OutputIterator>
    OutputIterator copy_n(InputIterator first, Size n,
                          OutputIterator result);

  template<class InputIterator, class OutputIterator, class Predicate>
    OutputIterator
      copy_if(InputIterator first, InputIterator last,
              OutputIterator result, Predicate pred);

  // move:
  template<class InputIterator, class OutputIterator>
    OutputIterator
      move(InputIterator first, InputIterator last,
           OutputIterator result);

  // swap:
  template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator2
      swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1,
                  ForwardIterator1 first2);

  template<class InputIterator, class OutputIterator,
           class UnaryOperation>
    OutputIterator transform(InputIterator first, InputIterator last,
                             OutputIterator result, UnaryOperation op);

  template<class InputIterator1, class InputIterator2, class OutputIterator,
           class BinaryOperation>
    OutputIterator
      transform(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, OutputIterator result,
                BinaryOperation binary_op);

  template<class ForwardIterator, class T>
    void replace(ForwardIterator first, ForwardIterator last,
                 const T& old_value, const T& new_value);

  template<class ForwardIterator, class Predicate, class T>
    void replace_if(ForwardIterator first, ForwardIterator last,
                    Predicate pred, const T& new_value);

  template<class InputIterator, class OutputIterator, class T>
    OutputIterator
      replace_copy(InputIterator first, InputIterator last,
                   OutputIterator result,
                   const T& old_value, const T& new_value);

  template<class InputIterator, class OutputIterator, class Predicate, class T>
    OutputIterator
      replace_copy_if(InputIterator first, InputIterator last,
                      OutputIterator result, Predicate pred,
                      const T& new_value);

  template<class ForwardIterator, class T>
    void fill(ForwardIterator first, ForwardIterator last, const T& value);

  template<class OutputIterator, class Size, class T>
    void fill_n(OutputIterator first, Size n, const T& value);

  template<class ForwardIterator, class Generator>
    void generate(ForwardIterator first, ForwardIterator last, Generator gen);

  template<class OutputIterator, class Size, class Generator>
    OutputIterator generate_n(OutputIterator first, Size n, Generator gen);

  template<class ForwardIterator, class T>
    ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& value);

  template<class ForwardIterator, class Predicate>
    ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, Predicate pred);

  template<class InputIterator, class OutputIterator, class T>
    OutputIterator
      remove_copy(InputIterator first, InputIterator last,
                  OutputIterator result, const T& value);

  template<class InputIterator, class OutputIterator, class Predicate>
    OutputIterator
      remove_copy_if(InputIterator first, InputIterator last,
                     OutputIterator result, Predicate pred);

  template<class ForwardIterator>
    ForwardIterator unique(ForwardIterator first, ForwardIterator last);

  template<class ForwardIterator, typename BinaryPredicate>
    ForwardIterator unique(ForwardIterator first, ForwardIterator last,
                           BinaryPredicate pred);

  template<class InputIterator, class OutputIterator>
    OutputIterator
      unique_copy(InputIterator first, InputIterator last,
                  OutputIterator result);

  template<class InputIterator, class OutputIterator, class BinaryPredicate>
    OutputIterator
      unique_copy(InputIterator first, InputIterator last,
                  OutputIterator result, BinaryPredicate pred);

  template<class BidirectionalIterator>
    void reverse(BidirectionalIterator first, BidirectionalIterator last);

  template<class BidirectionalIterator, class OutputIterator>
    OutputIterator
      reverse_copy(BidirectionalIterator first,
                   BidirectionalIterator last, OutputIterator result);

  template<class ForwardIterator>
    ForwardIterator
      rotate(ForwardIterator first, ForwardIterator middle,
             ForwardIterator last);

  template<class ForwardIterator, class OutputIterator>
    OutputIterator
      rotate_copy(ForwardIterator first, ForwardIterator middle,
                  ForwardIterator last, OutputIterator result);

  // partitions:
  template<class InputIterator, class Predicate>
    bool is_partitioned(InputIterator first, InputIterator last, Predicate pred);

  template<class ForwardIterator, class Predicate>
    ForwardIterator
      partition(ForwardIterator first,
                ForwardIterator last, Predicate pred);

  template<class BidirectionalIterator, class Predicate>
    BidirectionalIterator
      stable_partition(BidirectionalIterator first,
                       BidirectionalIterator last, Predicate pred);

  template<class InputIterator, class OutputIterator1,
           class OutputIterator2, class Predicate>
  pair<OutputIterator1, OutputIterator2>
  partition_copy(InputIterator first, InputIterator last,
                 OutputIterator1 out_true, OutputIterator2 out_false,
                 Predicate pred);

  template<class ForwardIterator, class Predicate>
    ForwardIterator partition_point(ForwardIterator first,
                                    ForwardIterator last,
                                    Predicate pred);

  // sorting and related operations:
  // sorting:
  template<class RandomAccessIterator>
    void sort(RandomAccessIterator first, RandomAccessIterator last);

  template<class RandomAccessIterator, class Compare>
    void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

  template<class RandomAccessIterator>
    void stable_sort(RandomAccessIterator first, RandomAccessIterator last);

  template<class RandomAccessIterator, class Compare>
    void stable_sort(RandomAccessIterator first, RandomAccessIterator last,
                     Compare comp);

  template<class RandomAccessIterator>
    void partial_sort(RandomAccessIterator first,
                      RandomAccessIterator middle,
                      RandomAccessIterator last);

  template<class RandomAccessIterator, class Compare>
    void partial_sort(RandomAccessIterator first,
                      RandomAccessIterator middle,
                      RandomAccessIterator last,
                      Compare comp);

  template<class InputIterator, class RandomAccessIterator>
    RandomAccessIterator
      partial_sort_copy(InputIterator first, InputIterator last,
                        RandomAccessIterator result_first,
                        RandomAccessIterator result_last);

  template<class InputIterator, class RandomAccessIterator,
           class Compare>
    RandomAccessIterator
      partial_sort_copy(InputIterator first, InputIterator last,
                        RandomAccessIterator result_first,
                        RandomAccessIterator result_last,
                        Compare comp);

  template<class ForwardIterator>
    bool is_sorted(ForwardIterator first, ForwardIterator last);

  template<class ForwardIterator, class Compare>
    bool is_sorted(ForwardIterator first, ForwardIterator last,
                   Compare comp);

  template<class ForwardIterator>
    ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last);

  template<class ForwardIterator, class Compare>
    ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last,
                                    Compare comp);

  template<class RandomAccessIterator>
    void nth_element(RandomAccessIterator first, RandomAccessIterator nth,
                     RandomAccessIterator last);

  template<class RandomAccessIterator, class Compare>
    void nth_element(RandomAccessIterator first, RandomAccessIterator nth,
                     RandomAccessIterator last, Compare comp);


  // merge:
  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      merge(InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, InputIterator2 last2,
            OutputIterator result);

  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      merge(InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, InputIterator2 last2,
            OutputIterator result, Compare comp);

  template<class BidirectionalIterator>
    void inplace_merge(BidirectionalIterator first,
                       BidirectionalIterator middle,
                       BidirectionalIterator last);

  template<class BidirectionalIterator,
           class Compare>
    void inplace_merge(BidirectionalIterator first,
                       BidirectionalIterator middle,
                       BidirectionalIterator last, Compare comp);


  // set operations:
  template<class InputIterator1, class InputIterator2>
    bool includes(InputIterator1 first1, InputIterator1 last1,
                  InputIterator2 first2, InputIterator2 last2);

  template<class InputIterator1, class InputIterator2, class Compare>
    bool includes(InputIterator1 first1, InputIterator1 last1,
                  InputIterator2 first2, InputIterator2 last2,
                  Compare comp);

  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      set_union(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2,
                OutputIterator result);

  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      set_union(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2,
                OutputIterator result, Compare comp);

  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      set_intersection(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       OutputIterator result);

  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      set_intersection(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       OutputIterator result, Compare comp);

  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      set_difference(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     OutputIterator result);

  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      set_difference(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     OutputIterator result, Compare comp);

  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                               InputIterator2 first2, InputIterator2 last2,
                               OutputIterator result);

  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                               InputIterator2 first2, InputIterator2 last2,
                               OutputIterator result, Compare comp);

  // minimum and maximum:
  template<class ForwardIterator>
    ForwardIterator min_element(ForwardIterator first, ForwardIterator last);


  template<class ForwardIterator, class Compare>
    ForwardIterator min_element(ForwardIterator first, ForwardIterator last,
                                Compare comp);


  template<class ForwardIterator>
    ForwardIterator max_element(ForwardIterator first, ForwardIterator last);

  template<class ForwardIterator, class Compare>
    ForwardIterator max_element(ForwardIterator first, ForwardIterator last,
                                Compare comp);

  template<class ForwardIterator>
    pair<ForwardIterator, ForwardIterator>
      minmax_element(ForwardIterator first, ForwardIterator last);

  template<class ForwardIterator, class Compare>
    pair<ForwardIterator, ForwardIterator>
      minmax_element(ForwardIterator first, ForwardIterator last, Compare comp);

  template<class InputIterator1, class InputIterator2>
    bool
      lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2);

  template<class InputIterator1, class InputIterator2, class Compare>
    bool
      lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2,
                              Compare comp);

  // Utilities
  template<class InputIterator>
    typename iterator_traits<InputIterator>::value_type
      reduce(InputIterator first, InputIterator last);

  template<class InputIterator, class T>
    T reduce(InputIterator first, InputIterator last, T init);

  template<class InputIterator, class T, class BinaryOperation>
    T reduce(InputIterator first, InputIterator last, T init,
             BinaryOperation binary_op);

  template<class InputIterator, class OutputIterator>
    OutputIterator
      exclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result);
  

  template<class InputIterator, class OutputIterator,
           class T>
    OutputIterator
      exclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result,
                     T init);
  

  template<class InputIterator, class OutputIterator,
           class T, class BinaryOperation>
    OutputIterator
      exclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result,
                     T init, BinaryOperation binary_op);


  template<class InputIterator, class OutputIterator>
    OutputIterator
      inclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result);

  
  template<class InputIterator, class OutputIterator,
           class BinaryOperation>
    OutputIterator
      inclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result,
                     BinaryOperation binary_op);
  

  template<class InputIterator, class OutputIterator,
           class T, class BinaryOperation>
    OutputIterator
      inclusive_scan(InputIterator first, InputIterator last,
                     OutputIterator result,
                     T init, BinaryOperation binary_op);
} seq ; //
} // ::policy
} // ::parallel
} // ::std 

#include <bits/parallel/algos/seq/adjacent_difference.h>
#include <bits/parallel/algos/seq/adjacent_find.h>
#include <bits/parallel/algos/seq/all_of.h>
#include <bits/parallel/algos/seq/any_of.h>
#include <bits/parallel/algos/seq/copy.h>
#include <bits/parallel/algos/seq/copy_if.h>
#include <bits/parallel/algos/seq/copy_n.h>
#include <bits/parallel/algos/seq/count.h>
#include <bits/parallel/algos/seq/count_if.h>
#include <bits/parallel/algos/seq/equal.h>
#include <bits/parallel/algos/seq/exclusive_scan.h>
#include <bits/parallel/algos/seq/fill.h>
#include <bits/parallel/algos/seq/fill_n.h>
#include <bits/parallel/algos/seq/find.h>
#include <bits/parallel/algos/seq/find_end.h>
#include <bits/parallel/algos/seq/find_first_of.h>
#include <bits/parallel/algos/seq/find_if.h>
#include <bits/parallel/algos/seq/find_if_not.h>
#include <bits/parallel/algos/seq/for_each.h>
#include <bits/parallel/algos/seq/for_each_n.h>
#include <bits/parallel/algos/seq/generate.h>
#include <bits/parallel/algos/seq/generate_n.h>
#include <bits/parallel/algos/seq/includes.h>
#include <bits/parallel/algos/seq/inclusive_scan.h>
#include <bits/parallel/algos/seq/inner_product.h>
#include <bits/parallel/algos/seq/inplace_merge.h>
#include <bits/parallel/algos/seq/is_partitioned.h>
#include <bits/parallel/algos/seq/is_sorted.h>
#include <bits/parallel/algos/seq/is_sorted_until.h>
#include <bits/parallel/algos/seq/lexicographical_compare.h>
#include <bits/parallel/algos/seq/max_element.h>
#include <bits/parallel/algos/seq/merge.h>
#include <bits/parallel/algos/seq/min_element.h>
#include <bits/parallel/algos/seq/minmax_element.h>
#include <bits/parallel/algos/seq/mismatch.h>
#include <bits/parallel/algos/seq/move.h>
#include <bits/parallel/algos/seq/none_of.h>
#include <bits/parallel/algos/seq/nth_element.h>
#include <bits/parallel/algos/seq/partial_sort_copy.h>
#include <bits/parallel/algos/seq/partial_sort.h>
#include <bits/parallel/algos/seq/partition_copy.h>
#include <bits/parallel/algos/seq/partition.h>
#include <bits/parallel/algos/seq/partition_point.h>
#include <bits/parallel/algos/seq/reduce.h>
#include <bits/parallel/algos/seq/remove_copy.h>
#include <bits/parallel/algos/seq/remove_copy_if.h>
#include <bits/parallel/algos/seq/remove.h>
#include <bits/parallel/algos/seq/remove_if.h>
#include <bits/parallel/algos/seq/replace_copy.h>
#include <bits/parallel/algos/seq/replace_copy_if.h>
#include <bits/parallel/algos/seq/replace.h>
#include <bits/parallel/algos/seq/replace_if.h>
#include <bits/parallel/algos/seq/reverse_copy.h>
#include <bits/parallel/algos/seq/reverse.h>
#include <bits/parallel/algos/seq/rotate_copy.h>
#include <bits/parallel/algos/seq/rotate.h>
#include <bits/parallel/algos/seq/search.h>
#include <bits/parallel/algos/seq/search_n.h>
#include <bits/parallel/algos/seq/set_difference.h>
#include <bits/parallel/algos/seq/set_intersection.h>
#include <bits/parallel/algos/seq/set_symmetric_difference.h>
#include <bits/parallel/algos/seq/set_union.h>
#include <bits/parallel/algos/seq/sort.h>
#include <bits/parallel/algos/seq/stable_partition.h>
#include <bits/parallel/algos/seq/stable_sort.h>
#include <bits/parallel/algos/seq/swap_ranges.h>
#include <bits/parallel/algos/seq/transform.h>
#include <bits/parallel/algos/seq/unique_copy.h>
#include <bits/parallel/algos/seq/unique.h>


#endif
