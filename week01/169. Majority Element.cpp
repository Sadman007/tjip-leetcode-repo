// T - O(n), M - O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int appear = len/2 + 1;
        unordered_map<int,int> freq;
        for(auto num:nums){
            freq[num]++;
        }
        for(auto num:freq){
            if(num.second>=appear){
                return num.first;
            }
        }
        return -1;
    }
};
/**....................................................................**/

// T - O(nlogn), M - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        return nums[len/2];

    }
};
/**....................................................................**/

// T - O(n), M - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int voteCnt = 0, winner = 0;
        for(auto num:nums){
            if(voteCnt == 0) winner = num;
            if(winner == num){
                voteCnt++;
            }
            else{
                voteCnt--;
            }
        }
        return winner;
    }
};
