// Implementing a Queue from scratch using Array

#include <bits/stdc++.h>

class Queue{
public:
    int front = -1;
    int back = -1;
    int q[10]; // Array of size 10

    // Push function to add new values
    void push(int x){
        if(back < 9){ // Ensure queue does not overflow
            if(front == -1){
                front = 0;
            }
            back += 1;
            q[back] = x;
        } else {
            std::cout << "Queue overflow!" << std::endl;
        }
    }
    
    // Get the first element
    int peek_front(){
        if(front != -1){
            return q[front];
        } else {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
    }

    // Get the last element
    int peek_back(){
        if(back != -1){
            return q[back];
        } else {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
    }

    // Remove an element, in case of queue it is the front most element
    void pop(){
        if(front != -1 && front <= back){ // Ensure queue is not empty
            front += 1;
            if(front > back){ // Reset the queue if it becomes empty
                front = -1;
                back = -1;
            }
        } else {
            std::cout << "Queue is empty!" << std::endl;
        }
    }

    // Get the size of the queue
    int size(){
        if(front != -1) {
            return back - front + 1;
        } else {
            return 0; // Queue is empty
        }
    }

    // Check if the queue is empty
    bool empty(){
        return (front == -1);
    }
};

