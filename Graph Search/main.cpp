#include "graph.cpp"

int main()
{
    // test
    int n = 6;
    int m = 15;
    edge directedGraph[] = {{0, 4}, {0, 5}, {1, 0}, {1, 2}, {1, 4}, {2, 1}, {2, 3}, {2, 4}, {3, 2}, {3, 5}, {4, 0}, {4, 1}, {4, 3}, {5, 3}, {5, 4}};
    graph g(n, m, directedGraph, false);

    g.bfs(0);
    g.dfs(0);

    std::cout << g.connected();
}
