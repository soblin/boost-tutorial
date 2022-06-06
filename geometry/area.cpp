#include <iostream>
#include <boost/geometry/geometry.hpp>
#include <boost/assign/list_of.hpp>

int main() {
  namespace bg = boost::geometry;
  using Point = bg::model::d2::point_xy<double>;
  using Box = bg::model::box<Point>;
  using Polygon = bg::model::polygon<Point>;

  const Box x(Point(0, 0), Point(3, 3));
  std::cout << "sum is " << bg::area(x) << std::endl;

  Polygon poly;
  bg::exterior_ring(poly) =
      boost::assign::list_of<Point>(0, 0)(4, 0)(4, 6)(0, 4);
  std::cout << "sum is " << bg::area(poly) << std::endl;
}
