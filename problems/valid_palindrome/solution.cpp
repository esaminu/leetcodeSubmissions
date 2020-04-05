class Solution {
public:
    bool isAlphanumeric(char s) {
        bool isCapitalLetter = (s >= 'A') && (s<='Z');
        bool isSmallLetter = (s>='a') && (s<='z');
        bool isNumber = (s>='0') && (s<='9');
        return isCapitalLetter || isSmallLetter || isNumber;
    }
    
    char toLowerCase(char s) {
        bool isSmallLetter = (s>='a') && (s<='z');
        return isSmallLetter ? s : s + 32;
    }
    
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(!isAlphanumeric(s[i])) {
                i++;
                continue;
            }
            if(!isAlphanumeric(s[j])) {
                j--;
                continue;
            }
            if(toLowerCase(s[i]) == toLowerCase(s[j])) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        
        return true;
         
    }
};