#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>

using boost::multi_index::identity;
using boost::multi_index::indexed_by;
using boost::multi_index::multi_index_container;
using boost::multi_index::ordered_unique;
using boost::multi_index::sequenced;

using InsertionOrderedSet =
    multi_index_container<int,                                      // value
                          indexed_by<ordered_unique<identity<int>>, // key1
                                     sequenced<>                    // policy ?
                                     >>;

int main() {
  InsertionOrderedSet set;
  set.insert(1);
  set.insert(5);
  set.insert(4);
  set.insert(3);
  set.insert(2);

  // normal set --> 1,2,3,4,5
  for (const auto key : set) {
    std::cout << key << std::endl;
  }

  // as sequenced set --> 1,5,4,3,2
  for (const auto key : set.get<1>()) {
    std::cout << key << std::endl;
  }

  using AsNormalSet = InsertionOrderedSet::nth_index<0>::type;
  using AsOrderedSet = InsertionOrderedSet::nth_index<1>::type;

  {
    const AsNormalSet &s = set.get<0>();
    for (const auto key : s) {
      // pass
    }
  }
  {
    const AsOrderedSet &s = set.get<1>();
    for (const auto key : s) {
      // pass
    }
  }
}
