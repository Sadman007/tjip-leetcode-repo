// TC: O(NlogN)
// MC: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> long_seq(nums.begin(), nums.end());
        int longest_seq_len = 0;
        for(auto num : long_seq)
        {
            if(long_seq.count(num - 1) == 0)
            {
                int curr = num;
                while(long_seq.count(curr))
                {
                    curr++;
                }
                longest_seq_len = max(longest_seq_len, curr - num);
            }
        }
        return longest_seq_len;
    }
};
