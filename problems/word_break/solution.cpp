class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> v(s.size());
        return dfsSearch(s, wordDict, 0, v);
    }
    bool dfsSearch(string& s, vector<string> &wordDict, int i, vector<int> &memo) {
        if(i == s.size()) return true;
        if(memo[i]) return memo[i] == -1 ? false : true;
        for(string word: wordDict) {
            if(s.find(word, i) == i && dfsSearch(s, wordDict, i + word.size(), memo)) {
                memo[i] = 1;
                return true;   
            }
        }
        memo[i] = -1;
        return false;
    }
};