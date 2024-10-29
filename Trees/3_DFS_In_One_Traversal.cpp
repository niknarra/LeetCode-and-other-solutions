void threeWay(Node* root){
    stack<pair<Node*, int>> st;
    
    vector<int> pre;
    vector<int> post;
    vector<int> in;
    
    st.push({root,1});
    
    while(!st.empty()){
        Node* curr = st.top().first;
        int curr_count = st.top().second;
        st.pop();
        
        if(curr_count == 1) {
            pre.push_back(curr->value);
            st.push({curr, 2});
            if(curr->left) st.push({curr->left, 1});
        }
        else if(curr_count == 2) {
            in.push_back(curr->value);
            st.push({curr, 3});
            if(curr->right) st.push({curr->right, 1});
        }
        else post.push_back(curr->value);
    }
    cout << "Pre-Order: ";
    for (auto it : pre) cout << it << " ";
    cout << "\nIn-Order: ";
    for (auto it : in) cout << it << " ";
    cout << "\nPost-Order: ";
    for (auto it : post) cout << it << " ";
}

// In pre-order, we print the node the first time we see it
// In in-order, we print a node the second time we see it
// In post-order, we print a node the third time we see it
