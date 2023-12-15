#include <iostream>
#include <queue>
#include <vector>

using namespace std;


// Create a graph class
class Graph {
    public:
        Graph(int numVertices);
        void addEdge(int u, int v);
        void bfs(int startVertex);
        vector<pair<int, int>> traversedEdges;
        vector<int> traversalOrder;

    private:
        vector<vector<int>> adjList;     
};

// Constructor. Set the size of the adjacency list to the number of vertices
Graph::Graph(int numVertices) : adjList(numVertices+2) {}

// Add an edge to the graph stored as a 2D vector or array
void Graph::addEdge(int u, int v) { 
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

// Perform a breadth-first search starting from the given vertex
void Graph::bfs(int startVertex) {
    // Create a queue to store the vertices to be visited
    vector<bool> visited(adjList.size(), false);
    queue<int> vertexQueue;

    // Add the starting vertex to the queue and mark it as visited
    vertexQueue.push(startVertex);
    visited[startVertex] = true;

    // While the queue is not empty
    while (!vertexQueue.empty()) {

        // Get the next vertex in the queue
        int currentVertex = vertexQueue.front();

        // Remove the vertex from the queue
        vertexQueue.pop();

        // Add the current vertex to the traversal order
        traversalOrder.push_back(currentVertex);

        // Add the edges from the current vertex to the queue
        for (int neighbor : adjList[currentVertex]) {

            // If the neighbor has not been visited, add it to the queue and mark it as visited
            if (!visited[neighbor]) {
                vertexQueue.push(neighbor);
                visited[neighbor] = true;
                traversedEdges.push_back({currentVertex, neighbor});
            }
        }
    }
}

int main() {
    // Create a graph with 8 vertices
    int numVertices = 8;
    Graph graph(numVertices);
     
    // Add edges to the graph
    graph.addEdge(1, 2);
    graph.addEdge(1, 5);
    graph.addEdge(2, 6);
    graph.addEdge(6, 3);
    graph.addEdge(6, 7);
    graph.addEdge(3, 7);
    graph.addEdge(3, 4);
    graph.addEdge(4, 8);
    graph.addEdge(7, 8);
    graph.addEdge(7, 4);

    // Starting vertex: 2
    int startVertex = 2;

    // Perform a breadth-first search starting from the given vertex
    cout << "BFS Traversal starting from vertex " << startVertex << ": ";
    graph.bfs(startVertex);

    // Print the order of traversal
    cout << "\n\nOrder of Traversal: ";
    for (int vertex : graph.traversalOrder) {
        cout << vertex << " ";
    }

    // Print the traversed BFS graph
    cout << "\n\nTraversed BFS Graph Edges:" << endl;
    for (const auto& edge : graph.traversedEdges) {
        cout << edge.first << " -- " << edge.second << endl;
    }

    return 0;
}
