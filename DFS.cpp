// For quick testing, visit this link https://www.programiz.com/online-compiler/6VrRF3dtQGJk9

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int>> graph = {
    {0, {1, 2}},
    {1, {3, 4}},
    {2, {5}},
    {3, {}},
    {4, {5}},
    {5, {}}
};

const int graphSize = graph.size();

vector<string> state(graphSize, "new");
int dfsCounter = 0, finishCounter = 0;
vector<int> dfsNumbers(graphSize, -1);
vector<int> finishNumbers(graphSize, -1);

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

int main() {
    for (int i = 0; i < graphSize; ++i) {
        if (state[i] == "new") {
            dfs(i);
        }
    }

    cout << "States: ";
    for (const auto &s : state) {
        cout << s << " ";
    }
    cout << endl;

    cout << "DFS Numbers: ";
    for (const auto &num : dfsNumbers) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Finish Numbers: ";
    for (const auto &num : finishNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
