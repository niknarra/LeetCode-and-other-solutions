// Inorder Successor - The node that succeeds the target node in inorder traversal
// Inorder Predeccesor - The node that preceeds the target node in inorder traversal

// Approach 1 - Get inorder traversal and loop over it

class Solution
{
    public:
    
    void inorder(Node* root, vector<Node*>& ans){
        if(root == nullptr) return;
        
        inorder(root->left, ans);
        ans.push_back(root);
        inorder(root->right, ans);
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        vector<Node*> ans;
        inorder(root, ans);
        
        for(auto it:ans){
            if(it->key < key){
                pre = it;
            }
            if(it->key > key){
                suc = it;
                break;
            }
        }
    }
};

