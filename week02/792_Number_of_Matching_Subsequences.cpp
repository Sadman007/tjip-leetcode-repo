//792. Number of Matching Subsequences
//TC: O(N * |word| * log(|S|)   -> N := words.size()
//MC: O(|S|)

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> cnt[26];
        for(int i = 0; s[i]; i++){
            cnt[s[i]-'a'].push_back(i);
        }
        int res = 0;
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            int last = 0, isFound = 1;
            for(int j = 0; word[j]; j++){
                last = max(last, j);
                int cur = word[j] - 'a';
                int lo = lower_bound(cnt[cur].begin(), cnt[cur].end(), last) - cnt[cur].begin();
                if(lo == cnt[cur].size()){
                    isFound = 0;
                    break;
                }
                last = max(last, cnt[cur][lo]+1);
            }
            if(isFound) res++;

        }
        return res;
    }
};
