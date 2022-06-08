#include <utility>
#include <string>
#include <map>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>

enum class Node : int { A, B, C, D, E, N };
using Edge = std::pair<Node, Node>;
using Graph = boost::adjacency_list<boost::listS, boost::vecS, boost::directedS,
                                    Node, Edge>;

int main() {
  const std::vector<Edge> edges = {{Node::A, Node::B}, {Node::A, Node::C},
                                   {Node::A, Node::D}, {Node::B, Node::E},
                                   {Node::C, Node::E}, {Node::D, Node::E}};
  Graph g;
  // add Node
  std::map<Node, Graph::vertex_descriptor> desc;
  desc[Node::A] = boost::add_vertex(g);
  desc[Node::B] = boost::add_vertex(g);
  desc[Node::C] = boost::add_vertex(g);
  desc[Node::D] = boost::add_vertex(g);
  desc[Node::E] = boost::add_vertex(g);
  //// this name is used for added nodes in the order of addition
  const std::string name = "12345";
  // add edges
  boost::add_edge(desc[Node::A], desc[Node::B], g);
  boost::add_edge(desc[Node::A], desc[Node::C], g);
  boost::add_edge(desc[Node::A], desc[Node::D], g);
  boost::add_edge(desc[Node::B], desc[Node::E], g);
  boost::add_edge(desc[Node::C], desc[Node::E], g);
  boost::add_edge(desc[Node::D], desc[Node::E], g);
  boost::print_graph(g, name.c_str());
}
