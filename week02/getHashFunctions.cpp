//1) string ta sort thaka lgbe
// TC = O(NlogN) + O(N)
// MC = O(logN)--> sort er jonno
long long getHash(string &str){
    long long h = 0;
    for(auto ch: str){
        h = (h*base)+ch;
        h%=MOD;
    }
    return h;
}

//2) string ta sort thaka lgbe na
// TC = O(N)
// MC = O(1)
const long long MOD = 202206214218227LL; // use a large sophie germain prime for less collisions! FYI, 10^9 + 7 is a sophie germain prime.
long long getHash(string &s) {
    long long h = 1;
    for (auto c : s) {
        // here, M is a offset..In this problem M = base = 257
        h = (h * (c + 257)) % MOD;// (A0 + M)*(A1 + M)*(A2 + M)*...*(An-1 + M)
    }
    return h;
}

//3) string ta sort thaka lgbe na
// TC = O(N)
// MC = O(1)
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

//1) Range Hash function
unsigned long long getRangeHash(int L,int R){
    unsigned long long x1 = prefixHashHaystack[R];
    unsigned long long x2 = (L==0)? 0: (prefixHashHaystack[L-1]*po[R-L+1]);
    return (x1-x2);
}

//2) Range Hash function
int BASE = 29;
long long MOD = 1000000007;//202206214218227
long long getRangeHash(int L,int R){
    long long x1 = prefixHashHaystack[R];
    long long x2 = (L==0)? 0: (prefixHashHaystack[L-1]*po[R-L+1]) % MOD;
    return (x1-x2 + MOD) % MOD;
}

void preprocess(string &haystack){
    prefixHashHaystack[0] = haystack[0];

    for(int i=1;i<haystack.size();i++){
        prefixHashHaystack[i] = (1LL * prefixHashHaystack[i-1] * BASE) + haystack[i];

        po[i] = (po[i-1]*BASE);
    }
}
