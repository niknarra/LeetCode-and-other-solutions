// Implementing a Stack using a Single Queue
// After every push, we rotate the elements in the queue so the latest element is always at the front i.e., the top of the stack!

class stackQueue{
  
  Queue queue;
  int length = 0;
  
  public:
  
  void push(int x){
    queue.push(x);
    length += 1;
    
    for(int i=0;i<length-1;i+=1){
        queue.push(queue.peek_front());
        queue.pop();
    }
   }
   
   void pop(){
       
       if(!queue.empty()){
           queue.pop();
           length -= 1;
       }
   }
   
   int size(){
       if(!queue.empty()){
           return length;
       }
       return -1;
   }
   
   int top(){
       if(!queue.empty()){
           return queue.peek_front();
       }
       return -1;
   }
    
};


