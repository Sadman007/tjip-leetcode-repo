//205. Isomorphic Strings
//Time complexity - 0(n)
//space complexity - 0(1)
class Solution {
public:
    bool isIsomorphic(string s, string t , int iteration_count =0) {
        unordered_map<char , char> from;
        for(int i = 0; i <s.size(); i++){
         if(from.count(i) && from[s[i] != t[i]])
         {
             return false;
         }
        from[s[i]] = t[i];

       }

       if(iteration_count == 0) return isIsomorphic(t, s, 1);// base case
       return  true;
    }
};
