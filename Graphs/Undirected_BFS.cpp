#include <bits/stdc++.h>
using namespace std;

// TC: O(nodes+edges)
// SC: O(nodes)
// Approach 1 - Handles an undirected connected graph

void bfs(int start, int nodes, vector<vector<int>> adj){
    vector<int> vis(nodes+1, 0); // O(nodes)
    queue<int> q; // Queue to process nodes
    
    // Initializing the root and marking it as visited
    q.push(start); 
    vis[start] = 1;
    
    // While all the nodes are not processed,
    while(!q.empty()){ // O(nodes)
        int curr = q.front(); // Get the front most node
        q.pop(); // Pop it
        
        cout<<curr<< " "; // Print or store for traversal
        
        for(int node:adj[curr]){ // For each node, process it's neighbors -> O(edges)
            if(!vis[node]){ // If it is not visited,
                vis[node] = 1; // Mark it as visited
                q.push(node); // Push it to the queue to process it's neighbors
            }
        }
    }
    
}

// Approach 2 - Handles an undirected disconnected graph
// Keep the above bfs function as is, but introduce a helper function to make sure all the nodes are visited

vector<int> bfsOfGraph(int start, vector<vector<int>>& adj){
    vector<int> bfs_list;
    vector<int> vis(adj.size(), 0);
    
    for(int i=1;i<=adj.size();i+=1){
        if(!vis[i]){
            bfs(i, adj, vis, bfs_list);          
        }
    }
    return bfs_list;
}


int main() {
    cout << "Graphs"<<endl;
    
    int nodes, edges;
    cin>>nodes>>edges;
    
    vector<vector<int>> adj(nodes+1);
    
    // Creating the adjacency list  
    for(int i=0;i<edges;i+=1){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    // Printing the adjacency list
    for(int i=1;i<=nodes;i+=1){
        cout<<"Node: "<<i<<" ";
        for(int node:adj[i]){
            cout<<node<< " ";    
        }
        cout<<endl;
    }
    
    cout<<endl;
    
    bfs(1, nodes, adj);
    

    return 0;
}

