class MinStack {
    private:
        vector<int> List;
        stack<int> min;
        int lastIndex = -1;
public:
    /** initialize your data structure here. */
    MinStack() {
        // List = {};
        // lastIndex = -1;
    }
    
    void push(int x) {
        if(!min.size()) {
            min.push(x);
        } else {
            min.push(x <= min.top() ? x : min.top());
        }
        if(List.size() > lastIndex + 1) {
            List[lastIndex + 1] = x;
        } else {    
            List.push_back(x);
        }
        lastIndex++;
    }
    
    void pop() {
        if(lastIndex > -1) {
            min.pop();
            lastIndex--;
        }
    }
    
    int top() {
        return List[lastIndex];
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */