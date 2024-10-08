// Approach 1

class MyQueue {
public:

    stack<int> first;
    stack<int> second;

    MyQueue() {

    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        while(!first.empty()){
            second.push(first.top());
            first.pop();
        }
        int val = second.top();
        second.pop();
        while(!second.empty()){
            first.push(second.top());
            second.pop();
        }
        return val;
    }
    
    int peek() {
        while(!first.empty()){
            second.push(first.top());
            first.pop();
        }
        int val = second.top();
        while(!second.empty()){
            first.push(second.top());
            second.pop();
        }
        return val;
    }
    
    bool empty() {
        if(first.empty()){
            return true;
        }
        return false;
    }
};

// Approach 2
// More efficient as we use lazy transfer of elements

class MyQueue{

public:
	stack<int> main;
	stack<int> helper;
	
	MyQueue(){
	
	}

	void push(int x){

		main.push(x);	

	}	

	void pop(){

		if(helper.empty()){

			while(!main.empty()){
				
				helper.push(main.top());
				main.pop();
			}
		}
		int ans = helper.top();
		helper.pop();
		
		return ans;
	}
	
	void peek(){

		if(helper.empty()){

			while(!main.empty()){
		
				helper.push(main.top());
				main.pop();
			}
		}
		return helper.top();
	}
	

	void empty(){

		return main.empty() && helper.empty();

	}
};

