//49. Group Anagrams
//TC: O(N*|S|)   -> N := strs.size()
//MC: O(N*|S|)

class Solution {
public:
    string getKey(string s){
        int cnt[256] = {0};
        for(char ch : s) cnt[ch]++;
        string ret = "";
        for(int i = 0; i < 256; i++){
            for(int j = 0; j < cnt[i]; j++) ret += char(i);
        }
        return ret;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> bucket;
        for(auto s : strs){
            string key = s;
            bucket[getKey(key)].push_back(s);
        }

        vector<vector<string>> res;
        for(auto it : bucket) res.push_back(it.second);

        return res;
    }
};
