class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        vector<char> in = {'{', '(', '['};
        vector<char> out = {'}', ')',']'};
        
        for(int i = 0; i < s.length(); i++) {
            if(find(in.begin(), in.end(), s[i]) != in.end()) {
                stk.push(s[i]);
            } else {
                vector<char>::iterator oIt = find(out.begin(), out.end(), s[i]);

               if(oIt != out.end()) {
                   if(stk.size() && (oIt - out.begin()) == (find(in.begin(), in.end(), stk.top()) - in.begin())) {
                        stk.pop();
                   } else {
                       return false;
                   }
                } 
            }    
        }
        
        return !stk.size();
        
    }
};