// https://youtu.be/pXG3uE_KqZM
// TC = O(N*L*L) where N = length of words, L = max length of each word.
// MC = O(N*L)
bool cmp(string a,string b){
    return a.size() < b.size();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {

        unordered_map<string,int> check;
        sort(words.begin(),words.end(),cmp);

        int longestChain = 0;
        for(auto &word:words){// O(N)
            check[word] = 1;
            for(int i = 0; i < word.size(); i++){// O(L)
                string str = word.substr(0,i) + word.substr(i+1);// O(L)
                if(check.count(str)){
                    check[word] = max(check[word], check[str]+1);
                }
            }
            longestChain = max(longestChain, check[word]);
        }
        return longestChain;
    }
};
