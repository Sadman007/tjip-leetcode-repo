// TC: O(N)
// MC: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort -> [-5], [1, 2, 3, 4], [100], [200]
        // 2, -5, 3, 1, 100, 4, 200
        unordered_set<int>bucket(nums.begin(), nums.end()); // O(N)
        int longestSeqLen = 0;
        for (auto num : bucket)
        {
            if (bucket.count(num - 1) == 0)
            {
                // num -> starting element of sequence
                int curr = num;
                while(bucket.count(curr))
                {
                    curr++;
                }
                longestSeqLen = max(longestSeqLen, curr - num);
            }
        }
        return longestSeqLen;
    }
};