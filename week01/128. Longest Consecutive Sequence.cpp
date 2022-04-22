// TC: O(N)
// MC: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>bucket(nums.begin(),nums.end());
        
        int longest_seq_len = 0;
        for(auto num: bucket){
            if(bucket.count(num-1) == 0){
                int start_element = num;
                while(bucket.count(start_element)){
                    start_element++;
                }
                longest_seq_len = max(longest_seq_len,start_element - num);
            }
        }
        return longest_seq_len;
    }
};
