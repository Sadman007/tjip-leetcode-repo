// TC = O(N)
// MC = O(1)
class Solution {
public:
    string getHash(string &str){
        vector<int> freq(26,0);
        string hash = "";
        for(auto &c:str){
            freq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            hash += to_string(freq[i]) + (char)('a' + i);
        }
        return hash;
    }
    bool isAnagram(string s, string t) {
        if(getHash(s)==getHash(t)){
            return true;
        }
        return false;
    }
};
/************************************************/
// TC = O(N)
// MC = O(1)
class Solution {
public:
    const long long MOD = 202206214218227LL; // use a large sophie germain prime for less collisions! FYI, 10^9 + 7 is a sophie germain prime.
    long long getHash(string &s) {
        long long h = 1;
        for (auto c : s) {
            // here, M is a offset..In this problem M = base = 257
            h = (h * (c + 257)) % MOD;// (A0 + M)*(A1 + M)*(A2 + M)*...*(An-1 + M)
        }
        return h;
    }
    bool isAnagram(string s, string t) {
        return getHash(s) == getHash(t);
    }
};
/************************************************/
// TC = O(NLogN)
// MC = O(logN)
class Solution {
public:
    int base = 257;
    int MOD = 1000000007;

    long long getHash(string &str){
        long long h = 0;
        for(auto ch: str){
            h = (h*base)+ch;
            h%=MOD;
        }
        return h;
    }
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(getHash(s)==getHash(t)){
            return true;
        }
        return false;
    }
};
