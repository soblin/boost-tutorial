#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/strategies/transform.hpp>
#include <boost/geometry/strategies/transform/matrix_transformers.hpp>
#include <boost/geometry/algorithms/disjoint.hpp>

#include <cmath>
#include <iostream>

void main1() {
  namespace bg = boost::geometry;
  using point_type = bg::model::d2::point_xy<double>;
  bg::model::polygon<point_type> polygon;

  const int N = 10;
  polygon.outer().push_back(point_type(0.0, 0.0));
  for (int i = 1; i < N; ++i) {
    const double th = 2 * M_PI / N;
    const double x = std::cos(th), y = std::sin(th);
    polygon.outer().push_back(point_type(x, y));
  }
  polygon.outer().push_back(point_type(0.0, 0.0));

  std::cout << "polygon: " << bg::dsv(polygon) << std::endl;

  // do parallel transformation
  bg::model::polygon<point_type> shifted;
  bg::strategy::transform::translate_transformer<double, 2, 2> translate(0.9,
                                                                         1.0);
  bg::transform(polygon, shifted, translate);
  std::cout << "shifted: " << bg::dsv(shifted) << std::endl;

  // check intersection
  if (bg::intersects(polygon, shifted))
    std::cout << "intersects" << std::endl;
  else
    std::cout << "do not intersect" << std::endl;
}

void main2() {
  namespace bg = boost::geometry;
  using Point2D = bg::model::d2::point_xy<double>;
  using Box = bg::model::box<Point2D>;

  const Box a(Point2D(0, 0), Point2D(3, 3));
  const Box b(Point2D(4, 4), Point2D(7, 7));
  std::cout << bg::disjoint(a, b) << std::endl;
}

int main() {
  main1();
  main2();
  return 0;
}
