//28. Implement strStr()
//TC: O(N)
//MC: O(N)

class Solution {
public:
    #define MOD  1000000007
    #define base 29
    vector<long long> Hash, power;

    void preCal(string str){
        Hash[0] = str[0];
        for(int i = 1; str[i]; i++){
            Hash[i] = (Hash[i-1]*base + str[i])%MOD;
            power[i] = (power[i-1]*base)%MOD;
        }
    }

    long long needleHash(string needle){
        long long val = 0;
        for(int i = 0; needle[i]; i++){
            val = (val*base + needle[i]) % MOD;
        }
        return val;
    }

    long long getRangeHash(int lft, int rht){
        if(!lft) return Hash[rht];
        long long totalHash = Hash[rht];
        long long subHash = (Hash[lft-1]*power[rht - lft + 1])%MOD;
        return (MOD + totalHash - subHash) % MOD;
    }

    int strStr(string haystack, string needle) {
        int haySZ = haystack.size(), nedSZ = needle.size();
        Hash.resize(haySZ+1, 0);
        power.resize(haySZ+1, 1);
        preCal(haystack);
        long long needleHashValue = needleHash(needle);

        for(int i = 0; i+nedSZ-1 < haySZ; i++){
            long long hayHash = getRangeHash(i, i+nedSZ-1);
            if(hayHash == needleHashValue) return i;
        }
        return -1;
    }

};
