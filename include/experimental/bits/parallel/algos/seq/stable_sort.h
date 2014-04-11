#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class RandomAccessIterator>
    void sequential_execution_policy::stable_sort(RandomAccessIterator first, RandomAccessIterator last){
    std::stable_sort(first, last);
  }

  template<class RandomAccessIterator, class Compare>
    void sequential_execution_policy::stable_sort(RandomAccessIterator first, RandomAccessIterator last,
                          Compare comp){
    std::stable_sort(first, last, comp);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
