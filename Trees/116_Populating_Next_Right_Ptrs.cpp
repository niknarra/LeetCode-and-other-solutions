// BFS Approach
// TC: O(n) SC: O(m) m-> max no of nodes at a level

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* prev = nullptr; // To store the previous node at each level
            int numOfNodes = q.size();

            for(int i=0;i<numOfNodes;i+=1){
                Node* curr = q.front();
                q.pop();
		
		// If there is a previous node, set curr as its next node
                if(prev){
                    prev->next = curr;
                }
                prev = curr; // Update prev for next node

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            // The last node at each level will have nullptr as its right
            prev->next = nullptr;

        }
        return root;
    }
};
