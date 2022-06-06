#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp> // for random_generator
#include <boost/uuid/uuid_io.hpp>         // for conversion to string
#include <boost/lexical_cast.hpp>

int main() {
  using boost::uuids::random_generator;
  using boost::uuids::uuid;

  const uuid id1 = random_generator()();
  const uuid id2 = random_generator()();

  // to string
  const std::string str1 = boost::lexical_cast<std::string>(id1);
  const std::string str2 = boost::lexical_cast<std::string>(id2);

  std::cout << str1 << ", " << str2 << std::endl;
}
