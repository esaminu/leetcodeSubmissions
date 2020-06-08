class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        vector<int> ans;
        unordered_map<char, int> map;
        for(char c : p) {
            map[c]+=1;
        }
        unordered_map<char, int> currMap;
        int i = 0;
        while(i<=s.size()) {
            if(i < p.size()) {
                currMap[s[i++]]+=1;
                continue;
            }
            if(checkSameFreq(currMap, map)) ans.push_back(i - p.size());
            currMap[s[i - p.size()]]-=1;
            currMap[s[i++]]+=1;
        }
        return ans;
    }
    bool checkSameFreq(unordered_map<char, int> &mapA, unordered_map<char,int> &mapB) {
        for(auto it = mapA.begin(); it != mapA.end(); it++) {
            if(it->second != mapB[it->first]) {
                return false;
            }
        }
        
        return true;
    }
};