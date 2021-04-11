#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>

#include <iostream>
#include <string>
#include <vector>

int main()
{
    using namespace boost;
    // Select the graph type we wish to use
    typedef adjacency_list<vecS, vecS, directedS, property<vertex_color_t, default_color_type>>
        graph_t;
    // Set up the vertex IDs and names
    enum Vertex : int32_t
    {
        underwear,
        pants,
        belt,
        shirt,
        tie,
        jacket,
        socks,
        shoes,
        watch,
        N,
    };

    const std::vector<std::string> name = {"underwear", "pants", "belt",  "shirt", "tie",
                                           "jacket",    "socks", "shoes", "watch"};

    // Specify the edges in the graph
    typedef std::pair<int, int> E;
    E edge_array[] = {E(underwear, pants), E(underwear, shoes), E(pants, belt),
                      E(pants, shoes),     E(belt, jacket),     E(shirt, belt),
                      E(shirt, tie),       E(tie, jacket),      E(socks, shoes)};
    // Create the graph object
    const int n_edges = sizeof(edge_array) / sizeof(E);

    typedef graph_traits<graph_t>::vertices_size_type v_size_t;
    graph_t g(edge_array, edge_array + n_edges, v_size_t(N));

    typedef boost::graph_traits<graph_t>::vertex_descriptor vertex_t;

    std::vector<vertex_t> c;
    topological_sort(g, std::back_inserter(c));

    for (auto ii = c.rbegin(); ii != c.rend(); ++ii)
    {
        std::cout << name[*ii] << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}