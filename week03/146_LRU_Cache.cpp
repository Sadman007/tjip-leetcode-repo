//TC: O(N)  -> N := total operations
//MC: O(maxCapacity)

class LRUCache {
public:
    int maxCapacity;
    list<int> lru; //key rakhbo
    unordered_map<int, int> keyValue;  // keyValue[key] := value
    unordered_map<int, list<int> :: iterator> mp;

    LRUCache(int capacity) {
        maxCapacity = capacity;
    }

    int get(int key) {
        if(keyValue.count(key)) {
            update(key, keyValue[key], 1);
            return keyValue[key];
        }
        else return -1;
    }

    void put(int key, int value) {
        list<int>:: iterator it;
        if(keyValue.count(key)) update(key, value, 1);
        else if(lru.size() == maxCapacity){
            it = lru.end();
            --it;
            int lastKey = *it;
            evict(lastKey);
            update(key, value);
        }
        else update(key, value);
    }
    //helper functions
    void update(int key, int value, bool flag = 0){
        if(flag) lru.erase(mp[key]);
        lru.insert(lru.begin(), key);
        mp[key] = lru.begin();
        keyValue[key] = value;
    }

    void evict(int key){
        keyValue.erase(key);
        lru.erase(mp[key]);
        mp.erase(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
