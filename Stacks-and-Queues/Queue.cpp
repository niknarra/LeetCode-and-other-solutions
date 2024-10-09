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

// Implementing Queue using Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    
    Node(int newVal) {
        this->val = newVal;
        this->next = nullptr;
    }
};

class llQueue {
    Node* front = nullptr;
    Node* back = nullptr;

public:
    int length = 0;

    // Pushes an element to the back of the queue
    void push(int x) {
        Node* temp = new Node(x);
        if (front == nullptr) {
            front = temp;
            back = front;
        } else {
            back->next = temp;
            back = temp;
        }
        length += 1;
    }

    // Pops an element from the front of the queue
    void pop() {
        if (front != nullptr) {
            Node* temp = front;
            front = front->next;
            length -= 1;
            delete temp;
            if (front == nullptr) { // Reset back when queue is empty
                back = nullptr;
            }
        } else {
            cout << "Queue is Empty!" << endl;
        }
    }

    // Returns the size of the queue
    int size() {
        return length;
    }

    // Peeks at the front element of the queue
    int peek_front() {
        if (front != nullptr) {
            return front->val;
        } else {
            cout << "Queue is Empty!" << endl;
            return -1; // Or throw an exception
        }
    }

    // Peeks at the back element of the queue
    int peek_back() {
        if (back != nullptr) {
            return back->val;
        } else {
            cout << "Queue is Empty!" << endl;
            return -1; // Or throw an exception
        }
    }

    // Checks if the queue is empty
    bool empty() {
        return front == nullptr;
    }
};

