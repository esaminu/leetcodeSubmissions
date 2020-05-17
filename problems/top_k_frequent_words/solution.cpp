class wordFreq {
    
    public:
    string word;
    int freq;
    wordFreq(string word, int freq) {
        this->word = word;
        this->freq = freq;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> s;
        
        for(string i : words) s[i]++;
        
        auto comp = [](wordFreq const &A, wordFreq const &B) {
            return (A.freq == B.freq) ? (A.word < B.word) : (A.freq > B.freq);
        };
        
        priority_queue<wordFreq, vector<wordFreq>, decltype(comp)> qu(comp);
        
        for(auto it = s.begin(); it != s.end(); it++) {
            qu.push(wordFreq(it->first, it->second));
            if(qu.size() > k) {
                qu.pop();
            }
        }
        
        int size = qu.size();
        vector<string> res(qu.size());
        
        for(int i = size - 1; i >=0; i--) {
            res[i] = qu.top().word;
            qu.pop();
        }
        
        return res;
    }
};