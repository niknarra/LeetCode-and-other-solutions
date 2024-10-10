// Implementing a MinStack using a Stack

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

// MinStack Class
// PS. The above Stack Class is not designed to handle Pairs and expects int, so this code will cause errors but the logic is solid

class minStack{
  
  Stack st;
  pair<int,int> top = {-1,INT_MAX};
  int length = 0;
  
  public:
  
  void push(int x){
        int currentMin = st.empty() ? x : min(x, st.top().second);
        st.push({x, currentMin});
        length += 1;
    }
  
  void pop(){
      st.pop();
      length -= 1;
  }
  
  int top(){
      return st.top().first;
  }
  
  bool empty(){
      return st.empty();
  }
  
  int size(){
      return length;
  }
  
  int min(){
      return st.top().second;
  }
  
};

