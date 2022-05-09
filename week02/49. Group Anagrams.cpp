//Approach -1
//Time complexity- 0(N*K)
//Space complexity - 0(N*K)
class Solution {
public:
    unsigned long long getHash(string &strs){
        unsigned long long h = 1;

        for(auto ch : strs){
           h = h * (257 + (ch - 'a')) ;
        }
        return h;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<unsigned long long, vector<string>> mp;

        for(auto &x : strs){
            mp[getHash(x)].push_back(x);
        }

        vector<vector<string>> anagrams;
        for(auto x: mp){
            anagrams.push_back(x.second);
        }


        return anagrams;


    }
};

//Aproach-2
//Time complexity - 0(N*(K*logK)-N-length of strs,k-maximum length of string in strs.
//Space complexity - 0(N*K)
/*class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {


         vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto &x : strs){
            string tmp = x;
            sort(x.begin(),x.end());
            mp[x].push_back(tmp);
        }

        for(auto x: mp){
            ans.push_back(x.second);
        }

        return ans;


    }
};
*/
