// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include "Digraph.hpp"
#include <iostream>
#include <limits.h>

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
    for(int i = 0; i < distMatrix.size(); i++)
    {
        for(int j = 0; j < distMatrix[i].size(); j++)
        {
            distMatrix[i][j] = INT_MAX;
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

//    //check if edge exists before incrementing total number
//    if(distMatrix[source][dest] == INT_MAX && distMatrix[dest][source] == INT_MAX)
//        numberOfEdges++;

    //add weight of an edge
    distMatrix[source][dest] = wt;
    numberOfEdges++;

}

/**
 *  Deletes edge at the specified point
 * @param source The source of the edge
 * @param dest The destination of the edge
 */
void Digraph::delEdge(int source, int dest)
{
    distMatrix[source][dest] = INT_MAX;
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
    for( int i = 0; i < distMatrix.size() ; i++)
    {
        for (int j = 0; j < distMatrix[i].size(); j++)
        {
            std::cout << distMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Number of Edges: " << numberOfEdges << std::endl;

}