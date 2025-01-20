// For quick testing, visit this link https://www.programiz.com/online-compiler/9gf9SVxXPuk4J

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> graph = {
    {0, {5, 6}},
    {1, {2, 5}},
    {2, {4}},
    {3, {2}},
    {4, {2, 3}},
    {5, {1, 4}},
    {6, {7}},
    {7, {0, 1}}
};

int graphSize = graph.size();

vector<string> state(graphSize, "new");
int dfsCounter = 0;
vector<int> dfsNumbers(graphSize, -1), comp(graphSize, -1);

vector<int> oStack;
vector<int> rStack;

bool contains(const vector<int>& vec, int value) {
    for (int element : vec) {
        if (element == value) {
            return true;
        }
    }
    return false;
}

void dfs(int v) {
    state[v] = "active";
    dfsNumbers[v] = dfsCounter++;
    oStack.push_back(v);
    rStack.push_back(v);

    for (int edge : graph[v]) {
        if (state[edge] == "new") {
            dfs(edge);
        } else if (contains(oStack, edge)) {
            while (dfsNumbers[edge] < dfsNumbers[rStack.back()]) {
                rStack.pop_back();
            }
        }
    }

    state[v] = "finished";

    if (v == rStack.back()) {
        rStack.pop_back();
        int w = -1;
        while (w != v) {
            w = oStack.back();
            oStack.pop_back();
            comp[w] = v;
        }
    }
}

int main() {
    for (int i = 0; i < graphSize; i++) {
        if (state[i] == "new") {
            dfs(i);
        }
    }

    cout << "Components: ";
    for (int i = 0; i < comp.size(); i++) {
        cout << comp[i] << " ";
    }
    cout << endl;

    return 0;
}
