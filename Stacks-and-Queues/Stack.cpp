// Stack Implementation from scratch using Arrays

class Stack{
public:
    int top = -1;
    int st[10]; // Array of fixed size 10

    // Push an element onto the stack
    void push(int x){
        if(top < 9){ // Ensure stack does not overflow
            top += 1;
            st[top] = x;
        } else {
            std::cout << "Stack overflow!" << std::endl;
        }
    }

    // Peek at the top element without removing it
    int peek(){
        if(top != -1){
            return st[top];
        } else {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
    }

    // Pop an element off the stack
    void pop(){
        if(top != -1){
            top -= 1;
        } else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }

    // Check if the stack is empty
    bool empty(){
        return (top == -1);
    }

    // Get the size of the stack
    int size(){
        return top + 1;
    }
};


// Implementing Stack using Linked List

// Node Class
class Node{
    public:
    
    int val;
    Node* next;
    
    Node(int newVal){
        this->val = newVal;
        this->next = nullptr;
    }
    
    Node(int newVal, Node* newNext){
        this->val = newVal;
        this->next = newNext;
    }
};

// Stack with LL
class llStack{
    
    Node* top = nullptr;
    
    public:
    
    int length = 0;
    
    llStack(){
        
    }
    
    void push(int x){
        
        Node* temp = new Node(x, top);
        top = temp;
        length += 1;
        
    }
    
    void pop(){
        
        if(top!=nullptr){
        Node* temp = top;
        top = top->next;
        length -= 1;
        
        delete temp;
        }
        else{
            cout<<"Stack Empty!";
        }
    }
    
    int size(){
        return length;
    }
    
    int peek(){
       if(top!=nullptr) return top->val;
       
       return -1;
    }
    
    void empty(){
        
        return (top==nullptr);
        
    }
    
};


