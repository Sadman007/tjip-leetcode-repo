class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int vote=0,winner=0;
        for(auto num:nums){
            if(vote==0)
                winner=num;
            if(num==winner)
                vote++;
            else
                vote--;
        }
        return winner;
        
    }
};
