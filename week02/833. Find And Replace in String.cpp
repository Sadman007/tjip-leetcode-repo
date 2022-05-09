//Time complexity - 0(n+t) ; n = string length, t = number of targets
//space complexity - 0(n)
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,string>> bucket(s.length());
        for(int i = 0; i<indices.size() ; i++){
            if(s.compare(indices[i], sources[i].length(), sources[i]) == 0){
                bucket[indices[i]] = { sources[i].length(), targets[i]};
            }
        }

        string ans;
        int i = 0;
        while(i < s.length()){
            if(bucket[i].first){
                ans += bucket[i].second;
                i += bucket[i].first;
            }
            else{
                ans.push_back(s[i++]);
            }
        }
        return ans;
    }
}
