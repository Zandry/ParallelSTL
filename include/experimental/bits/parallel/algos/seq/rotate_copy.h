#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator, class OutputIterator>
    OutputIterator
      sequential_execution_policy::rotate_copy(ForwardIterator first, ForwardIterator middle,
                       ForwardIterator last, OutputIterator result) const {
    return std::rotate_copy(first, middle, last, result);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
