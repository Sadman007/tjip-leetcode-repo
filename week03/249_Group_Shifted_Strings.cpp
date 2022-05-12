//TC: O(n)  -> n := sum of all character of strings
//MC: O(n)

string calculateHash(string str){
    string curHash = "";
    for(char ch : str){
        curHash += to_string((ch - str[0] + 26)% 26);
    }
    return curHash;
}

vector<vector<string>> groupStrings(vector<string> &strings){
    vector<vector<string>> groups;
    unordered_map<string, vector<string>> mp;

    for(string str : strings){
        mp[calculateHash(str)].push_back(str);
    }
    for(auto it : mp){
        groups.push_back(it.second);
    }
    return groups;
}
