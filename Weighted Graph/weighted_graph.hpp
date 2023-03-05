#pragma once

#include <iostream>
#include <stack>

struct weightedEdge
{
    int s;    // starting vert
    int t;    // ending vert
    double w; // waga krawędzi
};

class WeightedGraph
{
private:
    double **adjWeightMatrix; // adjacency weighted matrix
    int n;                    // number of nodes
    bool directed;            // true if graph is directed, false graph is undirected

    /// @brief This function is search for the shortest path from verts
    /// @param visited array of visited verts
    /// @param d array of distance from verts
    /// @return index of vert we have the shortest path to
    int find(bool *visited, double *d);

    /// @brief This function will search for shortest path from verts
    /// @param s vert we start from
    /// @param t vert we end in
    /// @param parent array of parents of verts
    void shortestPath(int s, int t, int *parent);

public:
    /// @brief This function will use WarshallFloyd algorithm to show shortest path
    void WarshallFloyd();

    /// @brief Constructor of Weighted Graph object
    /// @param n number of nodes
    /// @param m number of edges
    /// @param edges array fill with weighted edges
    /// @param directed //true if graph is directed, false graph is undirected
    WeightedGraph(int n, int m, weightedEdge edges[], bool directed);

    /// @brief This function will use Dijkstra algorithm to show shortest path
    /// @param s vert we search from
    void Dijkstra(int s);
};