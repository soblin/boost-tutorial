#include <iostream>
#include <boost/geometry/geometry.hpp>

int main() {
  namespace bg = boost::geometry;
  using point = bg::model::d2::point_xy<double>;
  using box = bg::model::box<point>;

  const point bottom_left(0, 0);
  const point top_right(3, 3);
  const box b(bottom_left, top_right);

  const point p(1.5, 1.5);

  if (bg::within(p, b))
    std::cout << "within" << std::endl;
  else
    std::cout << "not within" << std::endl;
}
