#include <iostream>
#include <string>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>

using boost::multi_index::indexed_by;
using boost::multi_index::member;
using boost::multi_index::multi_index_container;
using boost::multi_index::ordered_unique;
using boost::multi_index::tag;

struct Product {
  int id;
  std::string name;

  Product(int id, std::string name) : id(id), name(name) {}
};

struct id {};
struct name {};

using Dictionary = multi_index_container<
    Product,
    indexed_by<ordered_unique<tag<id>, member<Product, int, &Product::id>>,
               ordered_unique<tag<name>,
                              member<Product, std::string, &Product::name>>>>;

int main() {
  Dictionary dict;
  dict.insert(Product(1, "apple"));
  dict.insert(Product(2, "orange"));
  dict.insert(Product(3, "banana"));
  {
    const auto &dict_name = dict.get<name>();
    if (const auto it = dict_name.find("apple"); it != dict_name.end()) {
      std::cout << it->id << std::endl;
    }
  }

  {
    const auto &dict_id = dict.get<id>();
    if (const auto it = dict_id.find(2); it != dict_id.end()) {
      std::cout << it->name << std::endl;
    }
  }
}
