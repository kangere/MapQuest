// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include "Digraph.hpp"
#include <iostream>
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
    for(const std::vector<int> edge:distMatrix)
    {
        //loop through each
        for(int weight: edge)
        {
            //weight with large numbers are treated as empty or null
            weight = 5;
        }
    }
}

/**
 * Adds an edge to the graph
 * @param source
 * @param dest
 * @param wt
 */
void Digraph::addEdge(int source, int dest, int wt)
{
    //add weight of an edge
    distMatrix[source][dest] = wt;

}

/**
 *  Deletes edge at the specified point
 * @param source The source of the edge
 * @param dest The destination of the edge
 */
void Digraph::delEdge(int source, int dest)
{
    distMatrix[source][dest] = 2100000000;
}

int Digraph::isEdge(int source, int dest)
{
}

int Digraph::dijkstra(int source, int dest)
{
}


//temp function
void Digraph::displayGraph()
{
    for( const std::vector<int> &edge  :distMatrix)
    {
        for (const int &weight : edge)
        {
            std::cout << weight << " ";
        }

        std::cout << std::endl;
    }

}