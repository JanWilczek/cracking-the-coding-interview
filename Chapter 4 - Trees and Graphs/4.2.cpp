#include "Graph.h"
#include <cassert>

using namespace std;

void visit(Graph& g, int vertexId, vector<bool>& visited)
{
	visited[vertexId] = true;

	for (const auto& edge : g.vertices[vertexId].neighbors)
	{
		if (!visited[edge.targetVertex]) visit(g, edge.targetVertex, visited);
	}
}

vector<bool> dfs(Graph& g, int startVertex)
{
	vector<bool> visited(g.vertices.size(), false);

	visit(g, startVertex, visited);

	return visited;
}

bool existsPath(Graph& g, int from, int to)
{
	auto visited = dfs(g, from);
	return visited[to];
}

void testExistsPath()
{
    auto g = testGraph();

    assert(existsPath(g, 1, 0));
    assert(!existsPath(g, 0, 4));
}

int main()
{
    testExistsPath();
}
