class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.size()) {
            int x = s2.top();
            s2.pop();
            return x;
        } else {
            while(s1.size()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if(s2.size()) {
            return s2.top();
        } else {
            while(s1.size()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            return s2.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return !s1.size() && !s2.size();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */