class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>charArray(26);

        for(int i=0;i<s.size();i++){

            charArray[s[i]-'a'].push_back(i);

        }

       int counts=0;

        for(int i=0;i<words.size();i++){
            int lastIndex=-1;
            bool isSeq=true;

            for(char w:words[i]){
                auto it=upper_bound(charArray[w-'a'].begin(),charArray[w-'a'].end(),lastIndex);

                if(it==charArray[w-'a'].end()){
                    isSeq=false;
                    break;
                }

                else{
                    lastIndex=*it;
                }
            }

            if(isSeq)
                counts++;
        }

        return counts;
    }
};
