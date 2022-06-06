#include <iostream>
#include <boost/geometry.hpp>

int main() {
  namespace bg = boost::geometry;
  using Point = bg::model::d2::point_xy<double>;
  const Point p1(1.0, 2.0);
  const Point p2(4.0, 6.0);
  std::cout << bg::distance(p1, p2) << std::endl;
}
