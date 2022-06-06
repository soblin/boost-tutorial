#include <iostream>
#include <boost/geometry.hpp>
#include <boost/assign/list_of.hpp>

int main() {
  namespace bg = boost::geometry;
  using Point = bg::model::d2::point_xy<double>;
  using Polygon = bg::model::polygon<Point>;
  using Box = bg::model::box<Point>;

  Polygon poly;
  bg::exterior_ring(poly) =
      boost::assign::list_of<Point>(2.0, 1.3)(2.4, 1.7)(3.6, 1.2)(4.6, 1.6)(
          4.1, 3.0)(5.3, 2.8)(5.4, 1.2)(4.9, 0.8)(3.6, 0.7)(2.0, 1.3);

  Box box;
  bg::envelope(poly, box);
  std::cout << bg::dsv(box) << std::endl;
}
