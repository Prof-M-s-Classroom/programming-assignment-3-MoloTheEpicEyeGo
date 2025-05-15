#include "heap.h"
#include <climits>
#include "graph.h"
#include <iostream>

//constructor that initializes adjacency matrix
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

//deconstructor to free adjacency matrix
Graph::~Graph()
{
    for (int i = 0; i < numVertices; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

//adds an undirected edge to the graph
void
Graph::addEdge(int u, int v, int weight)
{
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

//uses prim's algorithm to generate and print MST
void
Graph::primMST()
{
    int* key = new int[numVertices];
    int* parent = new int[numVertices];
    bool* inMST = new bool[numVertices];

    //initialize tracking arrays
    for (int i = 0; i < numVertices; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = false;
    }

    //starting node has cost 0
    key[0] = 0;
    MinHeap heap(numVertices);

    //initialize the heap with keys
    for (int v = 0; v < numVertices; v++)
    {
        heap.decreaseKey(v, key[v]);
    }

    //process all vertices
    while (!heap.isEmpty())
    {
        int u = heap.extractMin();
        inMST[u] = true;

        //update adjacent vertices
        for (int v = 0; v < numVertices; v++)
        {
            //if there's a connection from u to v, v is not in the mst yet, AND the edge to v is cheaper than the current best option
            if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v])
            {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
                heap.decreaseKey(v, key[v]);
            }
        }
    }

    //print mst and total cost
    int totalCost = 0;
    std::cout << "Edge\tWeight\n";
    for (int i = 1; i < numVertices; i++)
    {
        std::cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << "\n";
        totalCost += adjMatrix[i][parent[i]];
    }
    std::cout << "Total Cost: " << totalCost << "\n";

    //free memory
    delete[] key;
    delete[] parent;
    delete[] inMST;
}
