#include <vector>

struct Graph {
    template <typename T>
    using vector = std::vector<T>;

	struct Edge {
		int targetVertex;
	};

	struct Vertex {
		vector<Edge> neighbors;
	};
	
	vector<Vertex> vertices;
};

/**
 * Returns a sample directed graph for testing:
 * 0 --> 1, 2
 * 1 --> 2, 3
 * 2 --> 3, 0
 * 3 --> 2
 * 4 --> 3
 */
Graph testGraph()
{
    Graph g{{Graph::Vertex{{{1}, {2}}}, Graph::Vertex{{{2}, {3}}}, Graph::Vertex{{{3},{0}}}, Graph::Vertex{{{2}}}, Graph::Vertex{{{3}}}}};

    return g;
}
