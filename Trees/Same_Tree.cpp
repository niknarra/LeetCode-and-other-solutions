// Recursive Approach

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == nullptr && q == nullptr) {
        return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};

// Iterative Approach

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==nullptr && q==nullptr) return true; // If both trees are empty, they are same and there's nothing to compare

        if(p==nullptr || q==nullptr) return false; // If one of the trees is empty, then they are not same so early return

        deque<TreeNode*> q1;
        deque<TreeNode*> q2;

        q1.push_front(p); // Enque both the roots
        q2.push_front(q);

        while(!q1.empty() && !q2.empty()){ // While both the queues are not empty,
            TreeNode* curr_p = q1.front(); // Start processing the nodes
            TreeNode* curr_q = q2.front();
            q1.pop_front();
            q2.pop_front();

            if(curr_p->val != curr_q->val) return false; // If the currently processing nodes are not equal, return false
            
            if (curr_p->left && curr_q->left) { // If both the nodes have left childs,
                q1.push_back(curr_p->left);
                q2.push_back(curr_q->left);
                } else if (curr_p->left || curr_q->left) { // Or if one of them has a left child and the other doesn't
                    return false; // Return false and exit
                    }

            if (curr_p->right && curr_q->right) { // If both the nodes have right childs,
                q1.push_back(curr_p->right);
                q2.push_back(curr_q->right);
                } else if (curr_p->right || curr_q->right) { // Or if one of them has a right child and the other doesn't
                    return false; // Return false and exit
                    }
        }
        return q1.empty() && q2.empty(); // The while condition breaks when one of the queues is empty so check if both are empty

    }
};

