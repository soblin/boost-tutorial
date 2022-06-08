#include <iostream>
#include <string>
#include <array>
#include <chrono>
#include <unordered_set>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/functional/hash.hpp>

namespace std {
template <> struct hash<boost::uuids::uuid> {
  size_t operator()(const boost::uuids::uuid &uid) const {
    return boost::hash<boost::uuids::uuid>()(uid);
  }
};
} // namespace std

struct RoadmapNodeProp {
public:
  // This user data type should be passed from the client
  // So RoadmapGraph<UserNodePropT, UserEdgePropT, UserGraphPropT> ?
  struct Data {
    double value;
    std::array<double, 3> position;
    std::array<double, 4> orientation;
  };

  boost::uuids::uuid ID;
  std::vector<boost::uuids::uuid> edges; // connected edges
  std::chrono::system_clock::time_point stamp;
  Data data;
};

struct RoadmapEdgeProp {
public:
  struct Data {
    double weight;
    double length;
  };

  boost::uuids::uuid ID;
  std::chrono::system_clock::time_point stamp;
  Data data;
};

class RoadmapGraph
    : public boost::adjacency_list<boost::vecS, boost::vecS,
                                   boost::bidirectionalS, RoadmapNodeProp,
                                   RoadmapEdgeProp, boost::no_property> {
public:
  struct RoadmapGraphData {
    int n_nodes;
    int n_edges;
  };

  RoadmapGraph() { stamp = std::chrono::system_clock::now(); }
  boost::uuids::uuid add_node();
  boost::uuids::uuid add_edge();

private:
  std::chrono::system_clock::time_point stamp;
  std::unordered_set<boost::uuids::uuid> nodes;
  std::unordered_set<boost::uuids::uuid> edges;
  // cache the mapping
  std::unordered_map<boost::uuids::uuid, vertex_descriptor> uid2nodedesc;
  std::unordered_map<boost::uuids::uuid, edge_descriptor> uid2edgedesc;
  RoadmapGraphData data;
};

int main() {
  RoadmapGraph graph;

  // NOTE: RoadmapNode is ctored here. Unfortunately, you cannnot pass
  // initializer list here, so you need to init the node properties after
  // add_vertex :)
  // Roadmap::vertex_descriptor root = boost::add_vertex(graph);
  // graph[root].data.value = 0.1;
  // graph[root].data.position = {0.0, 0.0, 0.0};
  // graph[root].data.orientation = {0.0, 0.0, 0.0, 1.0};
  return 0;
}
