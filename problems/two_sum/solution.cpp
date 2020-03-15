class Item {
    public:
        int index;
        int value;
        Item(int index, int value) {
            this->index = index;
            this->value = value;
        }
        bool operator==(const Item& t) const
        {
            return value == t.value;
        }
};

class MyHashFunction { 
public: 
    size_t operator()(const Item& t) const
    { 
        return t.value; 
    } 
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<Item, MyHashFunction> itemSet; 
        for(int i = 0; i < nums.size(); i++) {
            unordered_set<Item>::const_iterator it = itemSet.find(Item(-1,nums[i]));
            if(it == itemSet.end()) {
                itemSet.insert(Item(i, target - nums[i]));
            } else {
                return vector<int>{it->index,i};
            }
        }
        return vector<int>{0,0};
    }
};