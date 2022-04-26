//TC: O(|S|
//MC: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> mp;
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;

        int res = 0, idx = 0, sz = s.size();
        while(s[idx]){
            string cur = "";
            cur += s[idx];
            idx++;
            bool flag = 0;
            if(s[idx]) {
                if(mp.count(cur + s[idx])){
                    res += mp[cur + s[idx]];
                    flag = 1;
                    idx++;
                }
            }
            if(flag == 0) res += mp[cur];
        }
        return res;
    }
};
