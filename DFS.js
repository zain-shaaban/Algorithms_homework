// This is an application of the DFS algorithm in JavaScript
// To run this, you could visit this link: https://www.programiz.com/online-compiler/3jRfcdSdZvHFw
// You could also run this in the console of any browser
// You cold also run this in your Node environment if you have Node installed

let graph = {
    0: [1, 2],
    1: [3, 4],
    2: [5],
    3: [],
    4: [5],
    5: []
};
const graphSize = Object.keys(graph).length;

let state = new Array(graphSize).fill("new");
let dfsCounter = 0, finishCounter = 0;
let dfsNumbers = [], finishNumbers = [];

const dfs = (v) => {
    state[v] = "active";
    dfsNumbers[v] = dfsCounter;
    dfsCounter++;

    graph[v].forEach(edge => {
        if(state[edge] == "new") {
            dfs(edge);
        }
    })

    state[v] = "finished";
    finishNumbers[v] = finishCounter;
    finishCounter++;
}

for (let i = 0; i < graphSize; i++) {
    if (state[i] == "new") {
        dfs(i);
    }
}

console.log("States: ", state);
console.log("DFS Numbers: ", dfsNumbers);
console.log("Finish Numbers: ", finishNumbers);

// Thank you for reading