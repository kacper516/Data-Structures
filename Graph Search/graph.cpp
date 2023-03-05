#include "graph.hpp"

graph::graph(int n, int m, edge *edges, bool directed)
{
	this->n = n;
	this->directed = directed;

	adjMatrix = new int *[this->n] {};
	for (int i = 0; i < n; i++)
		adjMatrix[i] = new int[n]{};

	// fill with edges
	for (int i = 0; i < m; i++)
	{
		adjMatrix[edges[i].s][edges[i].t] = 1;
		if (this->directed == false) // it means that graph is undirected
			adjMatrix[edges[i].t][edges[i].s] = 1;
	}
}

void graph::_dfs(int s, bool *visited)
{
	visited[s] = true;
	std::cout << s << " ";
	for (int i = 0; i < n; i++)
	{
		if (adjMatrix[s][i] == 1 && visited[i] == false && s != i)
			_dfs(i, visited);
	}
}

void graph::bfs(int s)
{
	bool *visited = new bool[n];
	std::queue<int> verts;

	verts.push(s);
	visited[s] = true;
	std::cout << "BFS: " << s << " ";

	while (!verts.empty())
	{
		int u = verts.front();
		verts.pop();

		for (int i = 0; i < n; i++)
		{
			if (visited[i] == false && adjMatrix[u][i] == 1 && u != i)
			{
				std::cout << i << " ";
				visited[i] = true;
				verts.push(i);
			}
		}
	}
	std::cout << std::endl;
}

void graph::dfs(int s)
{
	bool *visited = new bool[n]{false};
	std::cout << "DFS: ";
	_dfs(s, visited);

	std::cout << std::endl;
}

int graph::connected()
{
	bool *visited = new bool[n]{false};
	int number_component = 0;

	for (int i = 0; i < n; i++)
	{
		std::cout << "A connected component for a vertex: ";
		number_component++;
		_dfs(i, visited);
		if (visited[i] == false)
			_dfs(i, visited);
		std::cout << std::endl;
	}

	return number_component;
}

std::ostream &operator<<(std::ostream &out, graph &g)
{
	for (int i = 0; i < g.n; i++)
	{
		out << i + 1 << ". ";
		for (int j = 0; j < g.n; j++)
		{
			out << g.adjMatrix[i][j] << ' ';
		}
		out << '\n';
	}
	return out;
}
