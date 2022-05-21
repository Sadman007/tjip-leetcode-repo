// TC = O(1)
// MC = O(n)
class LRUCache {
public:
    int maxCapacity;

    list<int> lru;//key
    unordered_map<int,int> data;// key,value
    unordered_map<int, list<int>::iterator> dataAddress;// key,address

    LRUCache(int capacity) {
        maxCapacity = capacity;
    }

    int get(int key) {
        if(data.count(key)==0){
            return -1;
        }
        updateLRU(key);
        return data[key];
    }

    void put(int key, int value) {
        if(lru.size()==maxCapacity && data.count(key)==0){
            evict();
        }
        updateLRU(key);
        data[key] = value;
    }

    // list er majhe theke delete kore surute niye asa
    void updateLRU(int key){
        if(data.count(key)){
            lru.erase(dataAddress[key]);
        }
        lru.push_front(key);
        dataAddress[key] = lru.begin();
    }

    //cache full.. last theke baad dewa lgbe
    void evict(){
        data.erase(lru.back());// lru er last element delete kortesi..jeta data,dataAddress e ase
        dataAddress.erase(lru.back());
        lru.pop_back();
    }
};

