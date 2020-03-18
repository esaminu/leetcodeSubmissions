class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> set;
        int jewels = 0;
        
        for(int i = 0 ; i<J.size(); i++) {
            set.insert(J[i]);
        }
        
        for(int j = 0 ; j<S.size(); j++) {
            if(set.find(S[j]) != set.end()) {
                jewels+=1;
            }
        }
        
        return jewels;
        
    }
};