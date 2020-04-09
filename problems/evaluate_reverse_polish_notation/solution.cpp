class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ops;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                int op1 = ops.top();
                ops.pop();
                int op2 = ops.top();
                ops.pop();
                ops.push(op1+op2);
            } else if(tokens[i] == "-") {
                int op1 = ops.top();
                ops.pop();
                int op2 = ops.top();
                ops.pop();
                ops.push(op2-op1);
            } else if(tokens[i] == "/") {
                int op1 = ops.top();
                ops.pop();
                int op2 = ops.top();
                ops.pop();
                ops.push(op2/op1);
            } else if(tokens[i] == "*") {
                int op1 = ops.top();
                ops.pop();
                int op2 = ops.top();
                ops.pop();
                ops.push(op2*op1);
            } else {
                ops.push(stoi(tokens[i]));
            }
        }
        return ops.top();
    }
};