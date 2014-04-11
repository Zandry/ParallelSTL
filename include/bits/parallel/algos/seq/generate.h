#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator, class Generator>
    void seq::generate(ForwardIterator first, ForwardIterator last, Generator gen){
    std::generate(first, last, gen);
  }

} // namespace policy
} // namespace parallel
} // namespace std