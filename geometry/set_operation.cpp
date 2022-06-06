#include <iostream>
#include <vector>
#include <boost/geometry.hpp>
#include <boost/assign/list_of.hpp>

int main() {
  namespace bg = boost::geometry;
  using Point = bg::model::d2::point_xy<double>;
  using Polygon = bg::model::polygon<Point>;
  using Box = bg::model::box<Point>;

  const Box box(Point(2, 0), Point(6, 4.5));
  Polygon poly;
  bg::exterior_ring(poly) =
      boost::assign::list_of<Point>(1, 1)(5, 5)(5, 1)(1, 1);
  // (1) difference: box - (box ∩ poly)
  {
    std::vector<Polygon> out;
    bg::difference(box, poly, out);
    for (auto &&p : out) {
      std::cout << bg::dsv(p) << std::endl;
    }
  }
  // (2) intersection: (box ∩ poly)
  {
    std::vector<Polygon> out;
    bg::intersection(box, poly, out);
    for (auto &&p : out) {
      std::cout << bg::dsv(p) << std::endl;
    }
  }
  // (3) union: (box ∪ poly)
  {
    std::vector<Polygon> out;
    bg::union_(box, poly, out);
    for (auto &&p : out)
      std::cout << bg::dsv(p) << std::endl;
  }
}
