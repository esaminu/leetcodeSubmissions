bool isVowel(char s) {
        string vowels = "aeiou";
    
        return vowels.find(s) != -1;
 }

class Solution {
public:
    string removeVowels(string S) {
        S.erase(remove_if(S.begin(), S.end(), isVowel), S.end());
        return S;
    }
};

