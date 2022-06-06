#include <iostream>
#include <boost/geometry.hpp>
#include <cmath>

int main() {
  namespace bg = boost::geometry;
  using Point = bg::model::d2::point_xy<double>;
  using Polygon = bg::model::polygon<Point>;

  Polygon poly;
  const int N = 3;
  for (int i = 0; i < N; ++i) {
    const double th = 2 * M_PI * i / N;
    poly.outer().push_back(Point(std::cos(th), std::sin(th)));
  }

  namespace trans = bg::strategy::transform;
  trans::rotate_transformer<bg::radian, double, 2, 2> translate(M_PI / 2);
  // or trans::rotate_transformer<bg::degree, double, 2, 2> translate(90);
  Polygon rotated;
  bg::transform(poly, rotated, translate);
  std::cout << "input: " << bg::dsv(poly) << std::endl;
  std::cout << "output: " << bg::dsv(rotated) << std::endl;
}
