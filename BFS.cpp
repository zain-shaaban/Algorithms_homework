// For quick testing, visit this link https://www.programiz.com/online-compiler/7eYqUhJYv8lQC

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V);
    void addE(int u, int v);
    void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addE(int u, int v) {
    adj[u].push_back(v);
}

void Graph::BFS(int s) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    Graph g(7);

    g.addE(0, 3);
    g.addE(0, 4);
    g.addE(2, 1);
    g.addE(2, 3);
    g.addE(3, 5);
    g.addE(4, 2);
    g.addE(4, 3);
    g.addE(6, 1);

    cout << "BFS starting from node 0: ";
    g.BFS(0);

    return 0;
}