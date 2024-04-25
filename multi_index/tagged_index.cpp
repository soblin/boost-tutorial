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
using boost::multi_index::tag;

struct normal {};
struct order {};
using Container =
    multi_index_container<int, // value
                          indexed_by<ordered_unique<tag<normal>, identity<int>>,
                                     sequenced<tag<order>>>>;

int main() {
  Container c;
  c.insert(1);
  c.insert(5);
  c.insert(2);
  c.insert(4);
  c.insert(3);
  {
    const auto &s = c.get<order>();
    for (const auto key : s) {
      std::cout << key << std::endl;
    }
  }
}
