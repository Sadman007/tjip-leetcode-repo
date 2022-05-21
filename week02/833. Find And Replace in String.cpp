// TC: O(N + ML), where N is the length of S, M is the number of possible replaces, and L is the avg length of each source word.
// MC: O(N)

class Solution {
public:

    bool isPossible(string &s, int offset, string source){
        if(offset + source.size() > s.size()) return  false;
        for(int i = offset, j = 0; i<s.size() && j<source.size(); i++,j++){
            if(s[i]!=source[j]){
                return false;
            }
        }
        return true;
    }

    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, int> table;
        string modifiedString = "";

        for(int i=0;i<indices.size();i++){
            if(isPossible(s, indices[i], sources[i])){
                table[indices[i]] = i;
            }
        }
        for(int i=0; i<s.size();){
            if(table.count(i)){
                modifiedString += targets[table[i]];
                i += sources[table[i]].size();
            }
            else{
                modifiedString.push_back(s[i]);
                i++;
            }
        }
        return modifiedString;
    }
};
