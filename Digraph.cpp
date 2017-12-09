// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include "Digraph.hpp"
#include <iostream>
#include <limits.h>
#include <map>


/**
 * Function returns number of vertices in the graph
 * @return number of vertices
 */
unsigned int Digraph::noVertices() {
    return numberOfVertices;
}

/**
 * returns number of edges in the graph
 * @return the number of edges in the graph
 */
unsigned int Digraph::noEdges() {
    return numberOfEdges;
}

/**
 * Function resets all edges so as they don't contain a  valid weight
 */
void Digraph::resetEdges() {
    //loop through each edge
    for (auto &edge: distMatrix) {
        for (auto &weight: edge) {
            weight = INT_MAX;
        }
    }
}

/**
 * Adds an edge to the graph
 * @param source the starting point of the path
 * @param dest the end of the path
 * @param wt the weight of the edge
 */
void Digraph::addEdge(int source, int dest, int wt) {

    //check if edge exists before incrementing total number
    if (distMatrix[source][dest] == INT_MAX && distMatrix[dest][source] == INT_MAX)
        numberOfEdges++;

    //add weight of an edge
    distMatrix[source][dest] = wt;

}

/**
 *  Deletes edge at the specified point
 * @param source The source of the edge
 * @param dest The destination of the edge
 */
void Digraph::delEdge(int source, int dest) {
    distMatrix[source][dest] = INT_MAX;
}

/**
 * determines whether the two vertices given form an edge
 * @param source the first vertice
 * @param dest second vertice
 * @return true if is valid edge false otherwise
 */
bool Digraph::isEdge(int source, int dest) {
    return (distMatrix[source][dest] < INT_MAX);
}

/**
 * Algorithm retuns the shortest path from source to dest in graph
 * @param source the point where the path starts
 * @param dest the destination of the path
 * @return the shortest distance
 */
int Digraph::dijkstra(int source, int dest) {

    //return 0 if source and dest are the same
    if(source == dest)
        return 0;

    std::vector<int> D;

    //map stores paths
    std::map < int ,std::vector<std::string>> paths;

    //initialise all vertices to infinte number
    D.resize(noVertices(), INT_MAX);

    //set distance of source to itself as 0
    D[source] = 0;

    for (int i = 0; i < noVertices(); i++) {
        //find minvertex
        int v = 0;
        for (int j = 0; j < noVertices(); j++)
            if (vertex[j]->getStatus() == NOT_VISITED) {
                v = j;
                break;
            }
        for (int j = 0; j < noVertices(); j++) {
            if (vertex[j]->getStatus() == NOT_VISITED && (D[j] < D[v]))
                v = j;
        }



        //set vertice as visited
        vertex[v]->setStatus(VISITED);

        if (D[dest] < INT_MAX) { //shortest distance found
            //reset vertices to unvisited
            for(auto &node: vertex)
                node->setStatus(NOT_VISITED);

            //return distance
            return D[dest];
        }

        //relax edges
        for (int w = 0; w < noVertices(); w++) {
            //visit only valid edges
            if (isEdge(v, w)) {
                if (D[w] > (D[v] + distMatrix[v][w]))
                    D[w] = D[v] + distMatrix[v][w];


            }
        }

    }

}

