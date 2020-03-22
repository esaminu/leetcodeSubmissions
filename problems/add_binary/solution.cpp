class Solution {
public:
    int getIntAtI(string str, int idx) {
        if(idx < str.length()) {
            char c = str[idx];
            return c - '0'; 
        }
        return 0;
    }
    string addBinary(string a, string b) {
        int length = max(a.length(), b.length());
        int paddingLength = length - min(a.length(), b.length());
        string sum(length, '0');
        string padding(abs(paddingLength), '0');
        if(a.length() < b.length()) {
            a = padding + a;
        } else {
            b = padding + b;
        }
        
        int c = 0;
        
        for(int i = (length - 1); i >= 0 ; i--){
            int inta = getIntAtI(a, i);
            int intb = getIntAtI(b, i);
            sum[i] = '0' + ((inta ^ intb) ^ c);
            c = (inta & intb) | (inta & c) | (intb & c); 
        }
        
        if(c == 0) {
            return sum;
        }
        
        char carry = '0' + c;
        
        bool appendCarry = (a[0] == '1' && b[0] == '1') || (carry == '1' && b[0] == '1') || (carry == '1' && a[0] == '1');
        
        if(appendCarry) {
            return carry + sum;
        }
         
        for(int j = 0; j < length; j++) {
            if(sum[j] == '1') {
                if(j) {
                    sum[j-1] = carry;
                    return sum;
                } else {
                    return carry + sum;
                }
            }
        }
        
        
        
        return carry + sum;
        
    }
};