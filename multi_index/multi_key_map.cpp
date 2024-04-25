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

struct Person {
  int id;
  std::string name;
  int age;

  Person(int id, const std::string &name, int age)
      : id(id), name(name), age(age) {}
  void print() const {
    std::cout << id << ", " << name << ", " << age << std::endl;
  }
};

struct id {};
struct name {};
struct age {};

using Dictionary = multi_index_container<
    Person, // value,
    indexed_by<
        ordered_unique<tag<id>, member<Person, int, &Person::id>>, // key1
        ordered_unique<tag<name>,
                       member<Person, std::string, &Person::name>>, // key2
        ordered_unique<tag<age>, member<Person, int, &Person::age>> // key3
        > // multi keys
    >;

int main() {
  Dictionary dict{};
  dict.insert(Person(111, "bob", 30));
  dict.insert((Person(222, "alice", 20)));
  dict.insert(Person(333, "john", 40));

  {
    const auto &id_map = dict.get<id>();
    if (const auto it = dict.find(111); it != id_map.end()) {
      it->print();
    }
  }

  {
    const auto &name_map = dict.get<name>();
    if (const auto it = name_map.find("alice"); it != name_map.end()) {
      it->print();
    }
  }
}
