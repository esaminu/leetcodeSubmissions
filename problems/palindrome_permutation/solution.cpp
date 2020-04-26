class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hmap;
        int numEven = 0;
        
        for(int i = 0; i < s.size(); i++) {
            hmap[s[i]] = hmap[s[i]] + 1;
        }
        
        for(auto it = hmap.begin(); it != hmap.end(); it++) {
            if(it->second % 2 == 0) {
                numEven++;
            } 
        }
        return (hmap.size() - numEven) < 2; 
    }
};