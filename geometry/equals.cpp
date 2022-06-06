#include <iostream>
#include <boost/geometry.hpp>
#include <boost/geometry/algorithms/equals.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/geometries/adapted/boost_tuple.hpp>
#include <boost/assign/list_of.hpp>

BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)

int main() {
  namespace bg = boost::geometry;

  using point = boost::tuple<int, int>;
  bg::model::polygon<point> poly;
  bg::exterior_ring(poly) =
      boost::assign::tuple_list_of(0, 0)(0, 3)(3, 3)(3, 0)(0, 0);
  // various way of pushing `point` to polys
  // poly.outer().push_back(point(x, y)) is also good.
  const bg::model::box<point> box(point(0, 0), point(3, 3));
  const bool result = bg::equals(poly, box);

  std::cout << "equals: " << result << std::endl;
}
