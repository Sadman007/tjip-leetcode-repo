//TC: O(n*m)  -> n := number of unique string, m = length of each string
//MC: O(n*m)

long long MOD = 202206214218227LL;
long long BASE = 257LL;

bool differByOne(vector<string>& dict) {
    unordered_set<string> uniqueStrings;
    for(string str : dict) uniqueStrings.insert(str);

    vector<string> updatedDict;
    for(string str : uniqueStrings) updatedDict.push_back(str);
    int strLen = updatedDict[0].size();
    int numOfString = updatedDict.size();

    vector<long long> expo(strLen + 5);
    expo[strLen-1] = 1LL;
    for(int i = strLen-2; i >= 0; i--){
        expo[i] = (expo[i+1] * BASE) % MOD;
    }

    vector<long long> stringHashes;
    for(string str : updatedDict){
        long long curHash = 0;
        for(int i = 0; str[i]; i++){
            curHash = ((curHash * BASE) + str[i])% MOD;
        }
        stringHashes.push_back(curHash);
    }

    for(int i = 0; i < strLen; i++){
        unordered_map<long long, int> mp;
        for(int j = 0; j < numOfString; j++){ /// j'th string er i'th char change kore hash value
            long long curHash = stringHashes[j];
            long long newHash = (curHash + (BASE - updatedDict[j][i]) * expo[i]) % MOD;
            if(++mp[newHash] >= 2) return true;
        }
    }
    return false;
}
