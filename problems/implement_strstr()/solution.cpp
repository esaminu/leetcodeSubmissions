
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) {
            return -1;
        }
        if(haystack.length() == 0) {
            return 0;
        }
        int i = 0;
        int j = std::max(0,(int) needle.length() - 1);
        int index = -1;
        
        while(j < haystack.length()){
            if(haystack.substr(i, needle.length()) == needle){
                return i;
            }
            i++;
            j++;
        }
        return -1;
    }
};