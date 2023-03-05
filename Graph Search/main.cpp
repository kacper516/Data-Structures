#include "graph.cpp"

int main()
{
    int n = 6;
    int m = 15;
    edge directedGraph[] = {{0, 4}, {0, 5}, {1, 0}, {1, 2}, {1, 4}, {2, 1}, {2, 3}, {2, 4}, {3, 2}, {3, 5}, {4, 0}, {4, 1}, {4, 3}, {5, 3}, {5, 4}};
    graph g(n, m, directedGraph, false);

    g.bfs(0);
    g.dfs(0);

    std::cout << g.connected();
    /*g.ile_skladowych(0);
    g.czy_spojny_bfs(0);
    g.czy_spojny_dfs(0);
    g.connected_bfs();
    g.connected_dfs();
    std::cout<<std::endl;
    g.czy_spojny(0);
    g.czy_spojny(1);
    g.czy_spojny(2);
    g.czy_spojny(3);
    g.czy_spojny(4);

    std::cout<<g.connected();*/
    /*std::cout<<g<<std::endl;*/
}