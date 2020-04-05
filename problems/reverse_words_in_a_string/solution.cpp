class Solution {
public:
    string reverseWords(string s) {
        
        if(s.length() == 1) {
            return s == " " ? "" : s;
        }
        
        string str = "";
        
        int j = s.length() - 1;
        
        while(j > 0) {
            while(s[j] == ' ' && j>0) {
                j--;
            }
            
            if(str.length() && (j || s[0] != ' ')) {
                str+=' ';
            }
            
            int i = j;
            
            while(s[max(i, 0)] != ' ' && i >= 0) {
                i--;
            }
            
            int temp = i;
            
            while(i < j) {
                // cout << str << endl;
                str+= s[++i];
            }
            j = temp;
        }
        
        return str;
        
    }
};