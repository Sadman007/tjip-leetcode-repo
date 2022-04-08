class Solution {
public:
    int firstMissingPositive(vector<int>&vc) {
      ///Time => O(n)
      ///Space => O(n)
        
      set<int>allNums(vc.begin(),vc.end());
      for(int i = 1; i<=vc.size()+1; i++ )
      {
		    if(allNums.find(i) == allNums.end())
            {
                return i;
            }
      }
      return 0;  
    }
};
