#include<bits/stdc++.h>
using namespace std;
//TC: O(S), where S = sum of lengths of all strings.
//MC: O(S)
class Solution1{
public:

    string getHash(string str)
    {
        string h = "";
        for(int i=1;i<str.size();i++){
            int diff = str[i] - str[i-1];
            if(diff<0) diff += 26;
            h += to_string(diff) + "#";
        }
        return h;
    }

    vector<vector<string> > groupShiftedStrings(vector<string> strings)
    {
        unordered_map<string,vector<string> > hashedStrs;
        for(auto s:strings){
            string hash = getHash(s);
            hashedStrs[hash].push_back(s);
        }
        vector<vector<string> > strGroups;
        for(auto group: hashedStrs){
            strGroups.push_back({group.second});
        }
        return strGroups;
    }
};

/****************************************************/
//TC: O(S), where S = sum of lengths of all strings.
//MC: O(S)
class Solution{
public:
    long long MOD = 202206214218227LL;
    int base = 257;
    long long getHash(string str)
    {
        long long h = 0;
        for(auto c: str){
            h = (h*base) + ((c - str[0] + 26) % 26) + 1;
//            cout<<h<<"--\n";
            if(h>=MOD) h%=MOD;
        }
        return h;
    }

    vector<vector<string> > groupShiftedStrings(vector<string> strings)
    {
        unordered_map<long long,vector<string> > hashedStrs;
        for(auto s:strings){
            long long hash = getHash(s);
            hashedStrs[hash].push_back(s);
        }
        vector<vector<string> > strGroups;
        for(auto group: hashedStrs){
            strGroups.push_back({group.second});
        }
        return strGroups;
    }
};


int main()
{
    vector<string> s1 = {"abc","bcd","acef","xyz","az","ba","a","z"};
    vector<string> s2 = {"a"};
    Solution sol;
    vector<vector<string> > res = sol.groupShiftedStrings(s1);
    for(auto s:res){
        for(auto x:s){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<vector<string> > res2 = sol.groupShiftedStrings(s2);
    for(auto s:res2){
        for(auto x:s){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

