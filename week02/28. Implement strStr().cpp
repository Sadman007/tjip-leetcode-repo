// TC = O(N+M)
// MC = O(N)
class Solution {
public:
    vector<long long> prefixHashHaystack, po;
    int BASE = 29;
    long long MOD = 1000000007;//202206214218227 dile hbe na ei prb a

    void preprocess(string &haystack){
        prefixHashHaystack[0] = haystack[0];

        for(int i=1;i<haystack.size();i++){
            prefixHashHaystack[i] = (1LL * prefixHashHaystack[i-1] * BASE) % MOD;
            prefixHashHaystack[i] += haystack[i];

            po[i] = (po[i-1]*BASE)%MOD;
        }
    }

    long long getRangeHash(int L,int R){
        long long x1 = prefixHashHaystack[R];
        long long x2 = (L==0)? 0: (prefixHashHaystack[L-1]*po[R-L+1]) % MOD;
        return (x1-x2 + MOD) % MOD;
    }

    long long generateHash(string &needle){
        long long h=0;
        for(auto ch:needle){
            h = (h*BASE) + ch;
            h%=MOD;
        }
        return h;
    }

    int strStr(string haystack, string needle) {
        int lb = needle.size();
        int la = haystack.size();

        prefixHashHaystack.resize(la+1,0);
        po.resize(la+1,1);
        preprocess(haystack);

        long long nH = generateHash(needle);

        for(int i=0;i<=(la-lb);i++){
            if(getRangeHash(i,i+lb-1) == nH){
                return i;
            }
        }
        return -1;
    }
};
/******************************************************/
// TC = O(N+M)
// MC = O(N)
class Solution {
public:
    vector<unsigned long long> prefixHashHaystack, po;
    int BASE = 29;

    void preprocess(string &haystack){
        prefixHashHaystack[0] = haystack[0];

        for(int i=1;i<haystack.size();i++){
            prefixHashHaystack[i] = (1LL * prefixHashHaystack[i-1] * BASE) + haystack[i];

            po[i] = (po[i-1]*BASE);
        }
    }

    unsigned long long getRangeHash(int L,int R){
        unsigned long long x1 = prefixHashHaystack[R];
        unsigned long long x2 = (L==0)? 0: (prefixHashHaystack[L-1]*po[R-L+1]);
        return (x1-x2);
    }

    unsigned long long generateHash(string &needle){
        unsigned long long h=0;
        for(auto ch:needle){
            h = (h*BASE) + ch;
        }
        return h;
    }

    int strStr(string haystack, string needle) {
        int lb = needle.size();
        int la = haystack.size();

        prefixHashHaystack.resize(la+1,0);
        po.resize(la+1,1);
        preprocess(haystack);

        unsigned long long nH = generateHash(needle);

        for(int i=0;i<=(la-lb);i++){
            if(getRangeHash(i,i+lb-1) == nH){
                return i;
            }
        }
        return -1;
    }
};
/******************************************************/
// TC = O(N*M)
// MC = O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lb = needle.size();
        int la = haystack.size();

        for(int i=0;i<=(la-lb);i++){
            if(haystack.substr(i,lb) == needle){// a.substr(idx,len for searched string)
                return i;
            }
        }
        return -1;
    }
};
