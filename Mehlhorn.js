// This is an application of the Cheriyan Mehlhorn Gabow algorithm in JavaScript
// This code is a derivative of the DFS algorithm
// To run this, you could visit this link: https://www.programiz.com/online-compiler/52ETBTzhQfScS
// You could also run this in the console of any browser
// You cold also run this in your Node environment if you have Node installed

// This is an example graph
let graph = {
    0: [5, 6],
    1: [2, 5],
    2: [4],
    3: [2],
    4: [2, 3],
    5: [1, 4],
    6: [7],
    7: [0, 1]
};
const graphSize = Object.keys(graph).length;

// Initializing
let state = new Array(graphSize).fill("new");
let dfsCounter = 0;
let dfsNumbers = new Array(graphSize).fill(-1), comp = new Array(graphSize).fill(-1);

let oStack = [];
let rStack = [];

// The algorithm
const dfs = (v) => {
    state[v] = "active";
    dfsNumbers[v] = dfsCounter;
    dfsCounter++;

    oStack.push(v);
    rStack.push(v);

    graph[v].forEach(edge => {
        if(state[edge] == "new") {
            dfs(edge);
        }

        else if(oStack.includes(edge)) {
            while(dfsNumbers[edge] < dfsNumbers[rStack[rStack.length - 1]]) {
                rStack.pop();
            }
        }
    })

    state[v] = "finished";

    if(v == rStack[rStack.length - 1]) {
        rStack.pop();
        let w;
        while(w !== v) {
            w = oStack.pop();
            comp[w] = v;
        }
    }
}

for (let i = 0; i < graphSize; i++) {
    if (state[i] == "new") {
        dfs(i);
    }
}

// Checking the results
console.log("Components: ", comp);

// Thank you for reading