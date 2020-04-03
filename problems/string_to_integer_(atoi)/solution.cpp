class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int num = 0;
        int multiplier = 1;
        
        while(str[i] == ' ') {
            i++;
        }
        
        if(str[i] != '-' && str[i] != '+' && (str[i] > 57 || str[i] < 48)) {
            return num;
        }
        
        if(str[i] == '-') {
            multiplier = -1;
            i++;
        } else if(str[i] == '+') {
            i++;
        }
        
        int startIndex = i;
        
        for(; i<str.length(); i++) {
            if(str[i] > 57 || str[i] < 48) {
                break;
            }
        }
        
        int startPower = i - startIndex - 1;
        
        for(;startIndex < i; startIndex++) {
            int toAdd = (str[startIndex] - 48) * pow(10, startPower) < INT_MAX ? (str[startIndex] - 48) * pow(10, startPower) : INT_MAX;
            if((INT_MAX - toAdd) >= num) {
                num+= toAdd;
            } else {
                return multiplier == 1 ? INT_MAX : INT_MIN;
                break;
            }
            startPower--;
            
        }
        
        return num * multiplier;
    }
};