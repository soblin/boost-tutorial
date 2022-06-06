#include <iostream>
#include <boost/geometry.hpp>
#include <boost/assign/list_of.hpp>

int main() {
  namespace bg = boost::geometry;
  namespace trans = bg::strategy::transform;

  using Point = bg::model::d2::point_xy<double>;
  using Polygon = bg::model::polygon<Point>;

  Polygon poly;
  bg::exterior_ring(poly) =
      boost::assign::list_of<Point>(0, 0)(3, 3)(3, 0)(0, 0);

  trans::scale_transformer<double, 2 /* input dim */, 2 /* output dim */>
      translate(3.0 /* scale */);

  Polygon result;
  bg::transform(poly, result, translate);

  std::cout << bg::dsv(result) << std::endl;
  return 0;
}
