// TC = O(N)
// MC = O(S); S = size of all strings altogether
class Solution {
public:
    string getHash(string &str){
        vector<int> frequency(26,0);
        string hash = "";
        for(auto &c:str){
            frequency[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(frequency[i]==0) continue;
            hash += to_string(frequency[i]) + (char)('a' + i);
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string> > groups;
        for(auto &str:strs){
            groups[getHash(str)].push_back(str);
        }
        vector<vector<string> > anagrams;
        for(auto &unit: groups){
            anagrams.push_back({unit.second});
        }
        return anagrams;
    }
};
/*****************************************************/
// TC = O(NlogN)
// MC = MC = O(S); S = size of all strings altogether
class Solution {
public:
    int base = 29;
    int MOD = 1000000007;

    long long getHash(string &str){
        long long h = 0;
        for(auto ch: str){
            h = (h*base)+ch;
            h%=MOD;
        }
        return h;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<long long, vector<string> > sameHashString;
        vector<vector<string> > res;

        for(auto str:strs){
            string mainStr = str;
            sort(str.begin(),str.end());
            long long h = getHash(str);
            sameHashString[h].push_back(mainStr);
        }
        for(auto kv:sameHashString){
            res.push_back({kv.second});
        }
        return res;
    }

};
