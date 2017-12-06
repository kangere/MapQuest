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

   //check if edge exists before incrementing total number
   if(distMatrix[source][dest] == INT_MAX && distMatrix[dest][source] == INT_MAX)
       numberOfEdges++;

    //add weight of an edge
    distMatrix[source][dest] = wt;
    // numberOfEdges++;

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

bool Digraph::isEdge(int source, int dest)
{
	if(distMatrix[source][dest] < INT_MAX)
		return true;
	else
		return false;
}

int Digraph::dijkstra(int source, int dest)
{
	std::vector<int> D;
	
	//initialise all vertices to infinte number
	D.resize(numberOfVertices,INT_MAX);

	//set distance of source to itself as 0
	D[source] = 0;

	for(int i = 0; i < numberOfVertices; i++)
	{
		//find minvertex
		int v = 0;
		for(int j = 0; j < numberOfVertices;  j++)
			if(vertex[j]->getStatus == NOT_VISITED){v = j; break;}
		for(int j = 0; j < numberOfVertices; i++){
			if(vertex[j]->getStatus == NOT_VISITED && (D[j] < D[v]))
				v = j;
		}


		//set vertice as visited
		vertex[v]->setStatus(VISITED);
		
		if(D[dest] < INT_MAX) return D[dest];	

		//relax edges
		for(int w = 0; w < numberOfVertices;w++){
			//visit only valid edges
			if(isEdge(v,w))
			{
				if(D[w] > (D[v] + distMatrix[v][w]))
					D[w] = D[v] + distMatrix[v][w];
			}
		}	

	}


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