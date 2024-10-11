// Implementing a Max Stack with a Stack

#include <bits/stdc++.h>
using namespace std;

class Stack {
    pair<int, int> top = {-1, -1};
    pair<int, int> st[10];  
    int length = -1;

public:
    void push(pair<int, int> x) {  
        if (length < 9) {  
            length += 1;
            top = x;  
            st[length] = top;
        } else {
            cout << "Stack is full!";
        }
    }

    pair<int, int> peek() {  
        return top;
    }

    void pop() {
        if (length > 0) {
            top = st[length - 1];
            length -= 1;
        } else if (length == 0) {
            length -= 1;
            top = {-1, -1};
        } else {
            cout << "Stack is empty!";
        }
    }

    int size() {
        return length + 1;
    }

    bool empty() {
        return length == -1;
    }
};


class MaxStack{
  
  Stack st;
  pair<int,int> top = {-1,INT_MIN};

  public:
  
  void push(int x) {
    if (st.empty() || x > top.second) {
        st.push({x, x});  
    } else {
        st.push({x, top.second});  
    }
    top = st.peek();  
  }
  
  void pop(){
    st.pop();
    top = st.peek();
  }
  
  pair<int,int> peek(){
      return top;
  }
  
  int max(){
      if (top.second != INT_MIN) return top.second;
      
      return -1;
  }
  
  int size(){
      return st.size();
  }
  
  bool empty(){
      return st.empty();
  }

};

