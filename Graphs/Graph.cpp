// Undirected Graph Representation and Storing
// Approach 1 - Adjacency Matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Undirected Graph w/ Adjacency Matrix"<<endl;
    int nodes, edges;
    cin >> nodes >> edges;
    int adj[nodes+1][nodes+1] = {0};
    
    for(int i=0;i<edges;i+=1){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}

// Assuming the input to be as follows - 
// 3 4
// 1 2
// 2 3
// 3 4
// 3 1

// But, the SC here will be O(n * n) for the matrix.

// Approach 2 - Adjacency List (Array)

int main() {
    cout << "Undirected Graph with Adjacency List"<<endl;
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj[nodes+1];
    
    for(int i=0;i<edges;i+=1){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}

// Here, we have a vector for each node that stores its neighbors
// The overall SC will be better than a adj matrix -> SC: O(nodes + edges)

// Directed Graph 
// We can use the same 2 approaches as an undirected graph. But, here the edges are directed, so the mapping will be done only once

// List
int main() {
    cout << "Directed Graph"<<endl;
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj[nodes+1];
    
    for(int i=0;i<edges;i+=1){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
       // This line is not necessary -> adj[v].push_back(u);
    }

    return 0;
}

// The SC in this case will be O(edges)

// Weighted Graph
// We can use the matrix or the list.
// In case of matrix,

int main() {
    cout << "Graphs"<<endl;
    int nodes, edges;
    cin >> nodes >> edges;
    int adj[nodes+1][nodes+1] = {0};
    
    for(int i=0;i<edges;i+=1){
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u][v] = wt;
        adj[v][u] = wt;
    }

    return 0;
}

// In case of list,

int main() {
    cout << "Graphs"<<endl;
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<pair<int,int>>> adj[nodes+1];
    
    for(int i=0;i<edges;i+=1){
        int u,v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    return 0;
}
