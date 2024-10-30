// Problem - Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

// The algorithm has three steps - 

// 1. Get the start node and in the same BFS traversal, map every node's parents

Node* mapParents(Node* root, int target, map<Node*, Node*>& parents){
	queue<Node*> q;
	q.push(root);

	Node* res = nullptr; // Node to store the start node and return	

	while(!q.empty()){
		
		Node* curr = q.front();
		q.pop();

		if(curr->value == target) res = curr; // Check for the start node

		if(curr->left){
			parents[curr->left] = curr; // Map the curr node as left child's parent
			q.push(curr->left); // Push to queue for traversal
		}

		if(curr->right){
			parents[curr->right] = curr; // Map the curr node as right child's parent
			q.push(curr->right); // Push to queue for traversal
		}
	}
	
	return res; // Return the start node, parents map is modified in place as we passed reference
}

// 2. Now we need to calculate the actual time taken to burn in the most optimal way

int burnTime(Node* start, map<Node*, Node*>& parents){
	queue<Node*> q; // Queue for BFS
	map<Node*, int> burned; // Map to store burnt nodes

	int timer = 0;	// Time keeper

	q.push(start); // Start by pushing the starting node to the queue
	burned[start] = 1; // And marking it as burned in the map
	
	while(!q.empty()){
		int nodesAtCurrLevel = q.size(); // For each level
		bool burn = false;		// Flag to check if there's a burn

		for(int i=0;i<nodesAtCurrLevel;i+=1){
			Node* curr = q.front();
			q.pop();

			if(curr->left && !burned[curr->left]){ // If there's a left child and it is not burnt
				bool = true; // Update the burn flag
				burned[curr->left] = 1; // Map the left child as burned
				q.push(curr->left); // Push to Q for BFS
			}	
				
			if(curr->right && !burned[curr->right]){ // If there's a right child and it is not burnt
				bool = true; // Update the burn flag
				burned[curr->right] = 1; // Map the right child as burned
				q.push(curr->right); // Push to Q for BFS
			}

			if(parents[curr] && !burned[parents[curr]]){ // If the curr node has a parent and it is not burnt
				bool = true; // Update the burn flag
				burned[parents[curr]] = 1; // Map the parent as burned
				q.push(parents[curr]); // Push to Q for BFS
			}
		}
		if(burn) timer += 1; // After every level iteration, update the time
	}
	return timer; // Return the final time
}

int minTime(Node* root, int target) 
    {
	map<Node*, Node*> parents;
	Node* start = mapParents(root, target, parents);
	int ans = burnTime(start, parents);

	return ans;   
}
