//833. Find And Replace in String
//TC: O(N * |S| + |S|)   -> N := indices.size()
//MC: O(N + |S|)

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int sz = s.size(), isValid[sz];
        memset(isValid, 0, sizeof isValid);

        for(int i = 0; i < indices.size(); i++){
            int pos = indices[i];
            string src = sources[i];
            string substr_of_s = s.substr(pos, src.size());
            if(src == substr_of_s) isValid[pos] = i+1;
        }
        string res = "";
        int idx = 0;
        while(s[idx]){
            if(isValid[idx]){
                int pos = isValid[idx] - 1;
                int len = sources[pos].size();
                res += targets[pos];
                idx += len;
            }
            else{
                res += s[idx];
                idx++;
            }
        }
        return res;
    }
};
