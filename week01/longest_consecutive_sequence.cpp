class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort -> [-5], [1,2,3,4], [100], [200]

        // nums = 2, -5, 3, 1, 100, 4, 200

        unordered_set<int> bucket(nums.begin(), nums.end());
         // O(N)
        int longestSeqLen = 0;

        for(auto num : nums) {

            if(bucket.count(num - 1) == 0) {
                int curr = num;
                //num -> starting element of sequence
                while(bucket.count(curr)) {
                    curr++;
                }
                longestSeqLen = max(longestSeqLen, curr - num);
            }
        }
        return longestSeqLen;
    }
};
