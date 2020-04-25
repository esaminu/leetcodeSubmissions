struct lruItem {
    int value;
    list<int>::iterator node;
};

class LRUCache {
private: 
    int capacity;
    unordered_map<int, lruItem> lruCache;
    list<int> currentKeys;
    
    void moveToBack(list<int>::iterator node) {
        currentKeys.push_back(*node);
        currentKeys.erase(node);
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(lruCache.find(key) != lruCache.end()) {
            moveToBack(lruCache.find(key)->second.node);
            lruCache[key].node = --currentKeys.end();
            return lruCache[key].value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lruCache.size() < capacity || lruCache.find(key) != lruCache.end()) {
            if(lruCache.find(key) == lruCache.end()) {   
                currentKeys.push_back(key);
            } else {
                moveToBack(lruCache.find(key)->second.node);
            }
            lruCache[key] = lruItem{value, --currentKeys.end()};
        } else {
            lruCache.erase(currentKeys.front());
            currentKeys.pop_front();
            put(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */