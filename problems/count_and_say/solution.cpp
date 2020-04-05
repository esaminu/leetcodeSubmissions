class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        
        for(int i = 1; i < n; i++) {
            
            str = getNextStr(str);
        }
        return str;
    }
    
    string getNextStr(string s) {
        string oStr = "";
        int i = 0;
        while(i < s.length()) {
            int j = i;
            while(s[j] == s[i] && j < s.length()) {
                j++;
            }
            char freq = (j - i) + 48;
            oStr += freq;
            oStr += s[i];
            i = j;
        }
        return oStr;
    }
};