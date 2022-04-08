class RandomizedSet {
public:
    vector<int>bucket;
    map<int,int>mp;
    int cnt = 0;
    
    RandomizedSet() {
        
       
    }
    
    bool insert(int val) {
        
        if(mp[val] > 0)
        {
            return false;
        }
        else
        {
            bucket.push_back(val);
            mp[val] = cnt+1;
            cnt++;
            return true;
        }
    }
    
    bool remove(int val) {
       
        if(mp[val] >0)
        {
            int currentIndex = mp[val];
            int lastIndex = bucket.size()-1;
            bucket[currentIndex-1] = bucket[lastIndex];
            mp[bucket[lastIndex]] =  mp[val];
            bucket.pop_back();
            cnt--;
            mp[val] = -1;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int getRandom() {
        int  len = bucket.size();
        int random = rand()%len;
        return bucket[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
