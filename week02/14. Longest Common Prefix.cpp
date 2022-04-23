//Time complexity - 0(s)- sum of all chraracter in all strings
//space complexity - 0(1)
class Solution {
public:
    string findPrefix(string prefix, string check){
        if(prefix.size() > check.size()) swap(prefix,check);

        string newPrefix = "";
        for(int i = 0 ; i< prefix.size(); i++){
          if(prefix[i] == check[i]) newPrefix  += (char)prefix[i];
          else
              break;
        }

        return newPrefix;
    }

    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0) return "";
        string prefix = strs[0];

        for(int i = 1; i < strs.size() ; i++){

                prefix = findPrefix(prefix, strs[i]);

        }

        return prefix;
    }
};
