// TC: O(N)
// MC: O(N)
class RandomizedSet {
public:
    vector<int> dataset;
    unordered_map<int, int> dataKeyIndex;
    random_device rd;
    RandomizedSet() {
        dataset = {};
    }
    
    bool insert(int val) {
        if (dataKeyIndex.find(val) != dataKeyIndex.end()) return false;
        dataKeyIndex[val] = dataset.size();
        dataset.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (dataKeyIndex.find(val) == dataKeyIndex.end()) return false;
        int delIndex = dataKeyIndex[val];
        int lastIndex = dataset.size() - 1;
        swap(dataset[delIndex], dataset[lastIndex]);
        dataset.pop_back();
        dataKeyIndex[dataset[delIndex]] = delIndex;
        dataKeyIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        int rdx = rd() % dataset.size();
        return dataset[rdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */