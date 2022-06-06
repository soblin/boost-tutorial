#include <iostream>
#include <cmath>
#include <boost/geometry.hpp>

int main() {
  namespace bg = boost::geometry;
  using Point = bg::model::d2::point_xy<double>;
  using Polygon = bg::model::polygon<Point>;

  Polygon poly;
  const int N = 5;
  poly.outer().push_back(Point(0, 0));
  for (int i = 1; i < N; ++i) {
    const double th = 2 * M_PI * i / N;
    poly.outer().push_back(Point(std::cos(th), std::sin(th)));
  }
  poly.outer().push_back(Point(0, 0));

  Polygon hull;
  bg::convex_hull(poly, hull);
  std::cout << "input: " << bg::dsv(poly) << std::endl;
  std::cout << "output: " << bg::dsv(hull) << std::endl;
}
