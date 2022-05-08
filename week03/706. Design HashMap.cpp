// TC = O(1)
// MC = O(N)
class MyHashMap {
public:
    unordered_map<int,int> hMap;
    MyHashMap() {
        hMap.clear();
    }

    void put(int key, int value) {
        hMap[key] = value;
    }

    int get(int key) {
        if(!hMap.count(key)){
            return -1;
        }
        return hMap[key];
    }

    void remove(int key) {
        if(hMap.count(key)){
            hMap.erase(key);
        }
    }
};
/***************************************************/

// TC = O(1)
// MC = O(N)
class MyHashMap {
public:
    unordered_map<int,int> hMap;
    MyHashMap() {
        hMap.clear();
    }

    void put(int key, int value) {
        hMap[key] = value;
    }

    int get(int key) {
        if(hMap.find(key)==hMap.end()){
            return -1;
        }
        return hMap[key];
    }

    void remove(int key) {
        if(hMap.find(key)!=hMap.end()){
            hMap.erase(key);

        }
    }
};

