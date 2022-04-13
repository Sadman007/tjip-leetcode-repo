class RandomizedSet {
public:
    vector<int> bucket;
    unordered_map<int,int> Mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(Mp.count(val))
        {
            return false;
        }
        bucket.push_back(val);
        Mp[val]=bucket.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
   
        if(!Mp.count(val))
        {
            return false;
        }
        int lastVal=bucket.back();
        bucket.pop_back();
        int last_index=Mp[lastVal];
        
        bucket[Mp[val]]=lastVal;

        Mp[lastVal]=Mp[val];
        Mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int index= rand()%bucket.size();
        return bucket[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
