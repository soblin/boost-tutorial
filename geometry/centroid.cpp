#include <iostream>
#include <boost/geometry.hpp>
#include <boost/assign/list_of.hpp>

int main() {
  namespace bg = boost::geometry;
  using Point = bg::model::d2::point_xy<double>;
  using Polygon = bg::model::polygon<Point>;

  // triangle
  Polygon poly;
  bg::exterior_ring(poly) = boost::assign::list_of<Point>(2, 0)(4, 3)(0, 3);
  Point p;
  bg::centroid(poly, p);
  std::cout << bg::dsv(p) << std::endl;
  // or
  const Point p1 = bg::return_centroid<Point>(poly);
  std::cout << bg::dsv(p1) << std::endl;
}
