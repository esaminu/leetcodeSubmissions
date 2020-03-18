class Solution {
public:
    string defangIPaddr(string address) {
      int first = address.find('.') ; 
      int second = address.find('.', first+1);
      int third = address.find('.', second+1);
        
      return address.substr(0, first) + "[.]" + address.substr(first + 1, second - (first + 1)) + "[.]" + address.substr(second + 1, third - (second + 1)) + "[.]" + address.substr(third + 1);
    }
};