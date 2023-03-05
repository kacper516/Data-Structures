#include "weighted_graph.cpp"

int main()
{
    int n = 6;
    int m = 12;
    weightedEdge edges[] = {{0, 1, 3}, {0, 3, 1}, {0, 4, 6}, {1, 2, 2}, {2, 5, 8}, {3, 1, 1}, {3, 2, 6}, {3, 4, 2}, {3, 5, 7}, {4, 0, 6}, {4, 3, 2}, {4, 5, 4}};
    WeightedGraph _graph(n, m, edges, false);
    _graph.Dijkstra(0);
    _graph.WarshallFloyd();
}