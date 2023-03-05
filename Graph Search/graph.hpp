#pragma once

#include <iostream>
#include <queue>

struct edge
{
public:
    int s; // starting vert
    int t; // ending vert
};

class graph
{
private:
    int **adjMatrix; // adjacency matrix
    int n;           // number of node
    bool directed;   // true - directed graph, false - undirected graph

    /// @brief Private method of dfs
    /// @param s vert we want to search for
    /// @param visited array with visited verts
    void _dfs(int s, bool *visited);

public:
    /// @brief Constructor of graph
    /// @param n number of nodes
    /// @param m number of edges
    /// @param edges struct array, fill with edges
    /// @param directed true if graph directed, else false
    graph(int n, int m, edge *edges, bool directed);

    /// @brief This function will use bfs algorithm
    /// @param s vert we start with
    void bfs(int s);

    /// @brief Public method for dfs
    /// @param s vert we start with
    void dfs(int s);

    /// @brief This function will check how many components are there (using private dfs method)
    /// @return number of components if 0, then the graph is connected
    int connected();

    /// @brief This function will print every node in graph
    /// @param out overload return statement
    /// @param g graph
    /// @return print statement contains every nodes
    friend std::ostream &operator<<(std::ostream &out, graph &g);
};