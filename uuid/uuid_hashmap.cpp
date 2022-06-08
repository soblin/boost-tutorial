#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp> // for random_generator
#include <boost/uuid/uuid_io.hpp>         // for conversion to string
#include <boost/lexical_cast.hpp>
#include <boost/functional/hash.hpp>

class Object {
public:
  Object(const std::string &name = "", double val = 0.0)
      : name(name), val(val) {
    uid = boost::uuids::random_generator()();
  }
  boost::uuids::uuid uid;
  const std::string name;
  const double val;
};

// https://stackoverflow.com/questions/16471051/boostuuidsuuid-as-a-key-in-stdunordered-map
// ATTENTION: do not miss 'const' qualifier, otherwise compiler tells tremendous
// errors
namespace std {
template <> struct hash<boost::uuids::uuid> {
  size_t operator()(const boost::uuids::uuid &uid) const {
    return boost::hash<boost::uuids::uuid>()(uid);
  }
};
} // namespace std

int main() {
  std::unordered_map<boost::uuids::uuid, std::shared_ptr<Object>> objects;
  std::vector<std::string> names = {"Tokyo", "New York", "Paris", "Hong Kong"};
  std::vector<double> vals = {0.0, 1.0, 2.0, 3.0};
  for (int i = 0; i < 4; ++i) {
    auto obj = std::make_shared<Object>(names[i], vals[i]);
    objects[obj->uid] = obj;
  }
}
