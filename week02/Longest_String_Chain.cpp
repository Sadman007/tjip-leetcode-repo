class Solution {
public:
   static bool compareString(string &s1,string &s2){
        if(s1.size()!=s2.size()+1) return false;

        int l=0;
        int r=0;

        while(l<s1.size()){
            if(s1[l]==s2[r]){
                l++;
                r++;
            }
            else{
                l++;
            }
        }

        if(l==s1.size() && r ==s2.size())return true;

        return false;

    }

   static bool compare(string &s1,string &s2){
        return s1.size()<s2.size();
    }


    int longestStrChain(vector<string>& words) {
        vector<int>mp(words.size(),1);

        sort(words.begin(),words.end(),compare);

        for(int i=1;i<words.size();i++){

            for(int j=0;j<i;j++){

                if(compareString(words[i],words[j])&&mp[i]<mp[j]+1)
                    mp[i]=mp[j]+1;


            }
        }

       return *max_element(mp.begin(),mp.end());
    }
};
