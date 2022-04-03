// T - O(n), M - O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(),nums.end());
        int longConSeq = 1;
        int mx = 0;
        for(int i=0;i<nums.size();i++){
            longConSeq = 1;
            if(seen.count(nums[i]-1)==0){
                int nextNumber = nums[i]+1;
                while(seen.count(nextNumber)){
                    longConSeq++;
                    nextNumber++;
                }
                mx = max(mx,longConSeq);
            }
        }
    return mx;
    }
};

/**....................................................................**/

// T - O(n), M - O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(),nums.end());
        int longestSeqLen = 0;

        for(auto num:nums){
            if(seen.count(num-1)==0){
                int curr = num;
                while(seen.count(curr)){
                    curr++;
                }
                longestSeqLen = max(longestSeqLen, curr - num);
            }
        }
        return longestSeqLen;
    }
};
