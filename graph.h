#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
    Graph(int vertices); //x
    ~Graph();//x
    void addEdge(int u, int v, int weight);//x
    void primMST();  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif