// LRU Cache Implementation and Design
// DS Used - Doubly Linked List, Map
// TC: O(n) SC: O(1)

class LRUCache {
public:
// Node Class for DLL
class Node{
    public:
    
    int val;
    int key;
    Node* prev;
    Node* next;

    Node(int newKey, int newVal){
        key = newKey;
        val = newVal;
    }
};

// Initialize the DLL and create the map that will actually be our cache
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> cache;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

// Helper function to remove a node from DLL
    void remove(Node* delNode){
        Node* front = delNode->next;
        Node* back = delNode->prev;

        back->next = front;
        front->prev = back;
    }

// Helper function to insert a node after head making it the most recently used
    void insertAfterHead(Node* newNode){
        Node* front = head->next;
        newNode->next = front;
        front->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
    
// Get function
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* resNode = cache[key];
            int ans = resNode->val;
            cache.erase(key);
            remove(resNode);
            insertAfterHead(resNode);
            cache[key] = head->next;

            return ans;
        }
        return -1;
    }
    
// Put function
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* currNode = cache[key];
            cache.erase(key);
            remove(currNode);
        }
        if(cache.size() == cap){
            cache.erase(tail->prev->key);
            remove(tail->prev);
        }
        insertAfterHead(new Node(key, value));
        cache[key] = head->next;
    }
};

