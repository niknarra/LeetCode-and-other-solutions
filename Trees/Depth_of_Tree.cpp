// Node Class init

#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  
  int value;
  Node* left;
  Node* right;
  
  Node(int newVal, Node* newLeft, Node* newRight){
      value = newVal;
      left = newLeft;
      right = newRight;
  }
  
  Node(int newVal){
      value = newVal;
      left = nullptr;
      right = nullptr;
  }
  
};

// Recursive Approach

int maxDepthOfTree(Node* root){
    
    if(root == nullptr){
        return 0;
    }
    
    return 1 + max(maxDepthOfTree(root->left), maxDepthOfTree(root->right)); // Essentially, the depth at a node will always be itself(1) + the max depth bw left and right
    
}

// Iterative Approach using BFS

int maxDepthWithBFS(Node* root){
    
    if(root==nullptr){
        cout<<"Empty Tree!";
        return 0;
    }
    
    deque<Node*> q; 
    q.push_front(root); // Enque the root
    int depth = 0; // Initially let the depth be 0
    
    while(!q.empty()){ 
        int nodesAtCurrLevel = q.size(); // Get the number of nodes at the current level, which will be the size of the queue
        depth += 1; // Increment the depth as there are node(s) at this level -> queue was not empty
        
        
        for(int i =0;i<nodesAtCurrLevel;i+=1){ // As long as queue has nodes from the current level, process them and pop
            Node* curr = q.front();
            q.pop_front();
            
            if (curr->left) q.push_back(curr->left);
            if (curr->right) q.push_back(curr->right);
        }
        
    }
    
    return depth;
}

// Both approaches use O(n) TC
