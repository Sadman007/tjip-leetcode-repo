class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> bucket(nums.begin(), nums.end());
        int longestSeqLen = 0;
        for (auto num : nums){
            if (bucket.count(num - 1) == 0){
                int curr = num;
                while (bucket.count(curr)) curr++;
                longestSeqLen = max(longestSeqLen, curr - num);
            }
        }
        return longestSeqLen;
    }
};