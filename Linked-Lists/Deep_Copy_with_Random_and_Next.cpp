class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Create all the copies of nodes and store them in a map
        unordered_map<Node*, Node*> map;
        Node* curr = head;
        while (curr != nullptr) {
            map[curr] = new Node(curr->val);  // Create a copy and map it
            curr = curr->next;
        }

        // Step 2: Assign next and random pointers using the map
        curr = head;
        while (curr != nullptr) {
            map[curr]->next = map[curr->next];     // Copy the next pointer
            map[curr]->random = map[curr->random]; // Copy the random pointer
            curr = curr->next;
        }

        // Return the head of the copied list
        return map[head];
    }
};
