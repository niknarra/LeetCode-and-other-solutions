class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return 1;

    int leftData = 0, rightData = 0;

    if (root->left) leftData = root->left->data;

    if (root->right) rightData = root->right->data;

    if (root->data == leftData + rightData && isSumProperty(root->left) && isSumProperty(root->right)) return 1;
    else return 0;

     
    }
};
