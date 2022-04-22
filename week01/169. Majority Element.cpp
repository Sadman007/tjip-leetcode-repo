// TC: O(N)
// MC: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner = 0;
        int vote_count = 0;
        for (auto num : nums){
            if(vote_count == 0)
                winner = num;
            
            if(num == winner)
                vote_count++;
            else 
                vote_count--;
        }
        
      return winner;
    }
};