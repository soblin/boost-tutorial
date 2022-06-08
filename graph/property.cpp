#include <iostream>
#include <string>
#include <array>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

struct RoadmapEdge;

struct RoadmapNode {
  boost::uuids::uuid ID;
  std::array<double, 3> position;
  std::vector<boost::uuids::uuid> edges;
};

struct RoadmapEdge {
  boost::uuids::uuid ID;
}
