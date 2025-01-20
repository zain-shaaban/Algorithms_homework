// For quick testing, visit this link https://www.programiz.com/online-compiler/8UmNuqSzNZ8Kb

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int>> graph = {
    {0, {1}},
    {1, {2}},
    {2, {0}}
};

const int graphSize = graph.size();

vector<string> state(graphSize, "new");
int dfsCounter = 0, finishCounter = 0;
vector<int> dfsNumbers(graphSize, -1);
vector<int> finishNumbers(graphSize, -1);

vector<string> tState(graphSize, "new");
int tDfsCounter = 0, tFinishCounter = 0;
vector<int> tDfsNumbers(graphSize, -1);
vector<int> tFinishNumbers(graphSize, -1);

void dfs(int v) {
    state[v] = "active";
    dfsNumbers[v] = dfsCounter++;

    for (int edge : graph[v]) {
        if (state[edge] == "new") {
            dfs(edge);
        }
    }

    state[v] = "finished";
    finishNumbers[v] = finishCounter++;
}

map<int, vector<int>> transposeGraph(const map<int, vector<int>> &g) {
    map<int, vector<int>> transposed;
    for (const auto &[node, edges] : g) {
        for (int edge : edges) {
            transposed[edge].push_back(node);
        }
    }
    return transposed;
}

map<int, vector<int>> transposed = transposeGraph(graph);

void tDfs(int v) {
    tState[v] = "active";
    tDfsNumbers[v] = tDfsCounter++;

    for (int edge : transposed[v]) {
        if (tState[edge] == "new") {
            tDfs(edge);
        }
    }

    tState[v] = "finished";
    tFinishNumbers[v] = tFinishCounter++;
}

bool isGraphStronglyConnected(const vector<string> &visitState) {
    for (int i = 0; i < graphSize; i++) {
        if (visitState[i] == "new") {
            return false;
        }
    }
    return true;
}

int main() {
    dfs(0);

    tDfs(0);

    if (isGraphStronglyConnected(state) && isGraphStronglyConnected(tState)) {
        cout << "Graph is strongly connected" << endl;
    } else {
        cout << "Graph is not strongly connected" << endl;
    }

    return 0;
}