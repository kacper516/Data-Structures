#include "weighted_graph.hpp"

int WeightedGraph::find(bool *visited, double *d)
{
	// we will compare with this value, and in constructor i use INT_MAX value to verts that is not in neighbourhood
	double minimum = INT_MAX;
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false && d[i] < minimum)
		{
			minimum = d[i];
			index = i;
		}
	}
	return index;
}

void WeightedGraph::shortestPath(int s, int t, int *parent)
{
	std::stack<int> _stack;
	_stack.push(t);
	while (t != s)
	{
		_stack.push(parent[t]);
		t = parent[t];
	}
	while (!_stack.empty())
	{
		std::cout << _stack.top() << " ";
		_stack.pop();
	}
	std::cout << std::endl;
}

void WeightedGraph::WarshallFloyd()
{
	double **distance = new double *[n];
	// rewrite values from array adjWeightMatrix
	for (int i = 0; i < n; i++)
	{
		distance[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			distance[i][j] = adjWeightMatrix[i][j];
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (distance[i][j] > distance[i][k] + distance[k][j])
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (distance[i][j] == INT_MAX)
				std::cout << "- ";
			else
				std::cout << distance[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				if (distance[i][j] < INT_MAX)
					std::cout << "Shortest path from " << i << " to " << j << " totals: " << distance[i][j] << std::endl;
				else
					std::cout << "Path from " << i << " to " << j << " doesn't exist." << std::endl;
			}
		}
		delete[] distance[i]; // to free memory
	}
	delete[] distance; // to free memory
}

WeightedGraph::WeightedGraph(int n, int m, weightedEdge edges[], bool directed)
{
	this->n = n;
	this->directed = directed;

	adjWeightMatrix = new double *[this->n];
	for (int i = 0; i < n; i++)
	{
		adjWeightMatrix[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				adjWeightMatrix[i][j] = 0;
			else
				adjWeightMatrix[i][j] = INT_MAX; // fill it right now with max value
		}
	}

	// fill it with edges
	for (int i = 0; i < m; i++)
	{
		adjWeightMatrix[edges[i].s][edges[i].t] = edges[i].w;
		if (this->directed == false)
			adjWeightMatrix[edges[i].t][edges[i].s] = edges[i].w;
	}
}

void WeightedGraph::Dijkstra(int s)
{
	double *distance = new double[n];
	int *parent = new int[n];
	bool *visited = new bool[n];

	for (int i = 0; i < n; i++)
	{
		distance[i] = INT_MAX;
		parent[i] = -1;
		visited[i] = false;
	}

	distance[s] = 0; // this is vert we start search from

	for (int i = 0; i < n; i++)
	{
		int u = find(visited, distance);
		visited[u] = true;

		for (int j = 0; j < n; j++)
		{
			if (adjWeightMatrix[u][j] != INT_MAX && u != j)
			{
				if (distance[j] > distance[u] + adjWeightMatrix[u][j])
				{
					distance[j] = distance[u] + adjWeightMatrix[u][j];
					parent[j] = u;
				}
			}
		}
	}

	std::cout << "Array visited (0 - unvisited, 1 - visited): ";
	for (int i = 0; i < n; i++)
		std::cout << visited[i] << " ";
	std::cout << std::endl;

	std::cout << "Array parent (-1 - unvisited, except the call vert): ";
	for (int i = 0; i < n; i++)
		std::cout << parent[i] << " ";
	std::cout << std::endl;

	std::cout << "Array distance (INT_MAX - unvisited vert): ";
	for (int i = 0; i < n; i++)
		std::cout << distance[i] << " ";
	std::cout << std::endl;

	// shortestPath(0,5, parent); example of call
}
