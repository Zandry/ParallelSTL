#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class EqualityComparable>
    typename iterator_traits<InputIterator>::difference_type
      sequential_execution_policy::count(InputIterator first, InputIterator last, const EqualityComparable &value){
    return std::count(first, last, value);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
