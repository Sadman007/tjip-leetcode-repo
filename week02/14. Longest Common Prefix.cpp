// TC = O(s); S = sum of all characters of all strings in the input list
// MC = o(1)
class Solution {
public:
    string findLCP(string &a, string &b){
        int idx = 0;
        // a[idx] && b[idx] diye a,b string a char ase kina check kore..ex = flower, flow
        // flower er 'w' er por 'e' ase but flow er 'w' er por kisu nai..so loop break korbe
        while(a[idx] && b[idx] && a[idx]==b[idx]){
            idx++;
        }
        return a.substr(0,idx);
    }

    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0];
        for(auto &str:strs){
            lcp = findLCP(lcp, str);
        }
        return lcp;
    }
};
