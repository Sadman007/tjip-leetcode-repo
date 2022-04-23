//Time complexity -O(n)
//space complexity - O(1)
class Solution {
public:
    vector<long long> prefHashHaystack , po;
    int base = 29;
    int mod = 1000000007;

    void preprocess(string &haystack){
        prefHashHaystack[0] = haystack[0];

        for(int i = 1; i < haystack.size() ; i++){
            prefHashHaystack[i] = (prefHashHaystack[i-1] * base)  % mod;
            prefHashHaystack[i] +=  haystack[i];
            po [i] = (po[i-1] * base) % mod;
        }
    }

    long long getRangeHash(int L, int R){
        int x1 = prefHashHaystack[R];
        int x2 = L==0? 0 : (prefHashHaystack[L-1] * po[R - L + 1]) % mod;

        return (x1 - x2 + mod) % mod;
    }

    long long generateHash(string &str){
        long long h = 0;
        for(auto s : str){
            h = h * base + s;
            h %= mod;
        }

        return h;
    }

    int strStr(string haystack, string needle) {

        int la = haystack.size();
        int lb = needle.size();

        prefHashHaystack.resize(la + 1, 0);
        po.resize(la + 1, 1);

        preprocess(haystack);

        long long nH = generateHash(needle);

        for(int i = 0; i<=la - lb ; i++){
          if(getRangeHash(i , i + lb - 1) == nH){
              return i;
          }
        }

        return -1;
    }
};
