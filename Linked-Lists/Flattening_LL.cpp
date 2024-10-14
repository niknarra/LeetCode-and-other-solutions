struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = nullptr;
        bottom = nullptr;
    }

};

class Solution{

    public:

    Node* merger(Node* l1, Node* l2){

        Node* dummy = new Node(-1);
        Node* dummyTemp = dummy;

        while(l1!=nullptr && l2!=nullptr){
            if(l1->data < l2->data){
                Node* temp = new Node(l1->data);
                dummyTemp->bottom = temp;
                dummyTemp = dummyTemp->bottom;
                l1 = l1->next;
            }else{
                Node* temp = new Node(l2->data);
                dummyTemp->bottom = temp;
                dummyTemp = dummyTemp->bottom;
                l2 = l2->next;
            }
        }

        if(l1){
            dummyTemp->bottom = l1;
        }

        if(l2){
            dummyTemp->bottom = l2;
        }

        return dummy->bottom;
    }

    Node* flatten(Node* root) {

        if(root == nullptr || root->next == nullptr){
            return root;
        }

        root->next = flatten(root->next);

        root = merger(root, root->next);

        return root;

    }


};
