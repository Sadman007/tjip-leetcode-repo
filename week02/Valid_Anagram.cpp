class Solution {
public:
    bool isAnagram(string s, string t) {

       if(s.size()!=t.size())
           return false;

        unordered_map<char,int>mp;

        for(int i=0;i<s.size();i++){
            auto it=mp.find(s[i]);

            if(it==mp.end())
                mp[s[i]]=1;
            else
                mp[s[i]]++;
        }
         for(int i=0;i<t.size();i++){
            auto it=mp.find(t[i]);

            if(it==mp.end())
                return false;
            else{
                mp[t[i]]--;
                if(mp[t[i]]<0)
                    return false;
            }

        }

        return true;
    }
};
