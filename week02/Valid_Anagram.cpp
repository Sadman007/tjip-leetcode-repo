#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int strLen1 = s.size();
        int strLen2 = t.size();
        
        if(strLen1 != strLen2) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        for(int i=0; i<strLen1; i++)
        {
            if(s[i] != t[i]) return false;
        }
        return true;
    }
};