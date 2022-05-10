// TC = O(n*m)
// MC = O(n)
class Solution{
public:
    const static long long MOD = 202206214218227LL;

    long long getHash(string &str){
        long long h;
        for(auto ch:str){
            h = (h*257)+ch;
            if(h>=MOD) h%=MOD;
        }
        return h;
    }

    bool differByOne(vector<string> &dict){
        unordered_set<long long> hashedString;
        int len = dict[0].size();
        for(auto curr:dict){

            long long currHash = getHash(curr);
            long long mult = 1;

            for(int i = len-1; i>=0; i--){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(curr[i]==ch) continue;
                    int diff = ch - curr[i];
                    long long newHash = currHash + (1LL * diff * mult )%MOD +MOD;
                    if(newHash >= MOD) newHash%=MOD;

                    if(hashedString.count(newHash)) return true;
                }
                mult = (mult * 257) % MOD;
            }
            hashedString.insert(currHash);
        }
        return false;
    }
};
