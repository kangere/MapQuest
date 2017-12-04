// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include "Digraph.hpp"
/**
 * Function returns number of vertices in the graph
 * @return number of vertices
 */
unsigned int Digraph::noVertices()
{
    return numberOfVertices;
}

unsigned int Digraph::noEdges()
{
    return numberOfEdges;
}

void Digraph::resetEdges()
{
    //loop through each edge
    for(auto const edge:distMatrix)
    {
        //loop through each
        for(auto item: edge)
        {
            item = NULL;
        }
    }
}

void Digraph::addEdge(int source, int dest, int wt)
{
}

void Digraph::delEdge(int source, int dest)
{
}

int Digraph::isEdge(int source, int dest)
{
}

int Digraph::dijkstra(int source, int dest)
{
}