class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store(nums.begin(), nums.end());
        int longestSeq = 0;
        for(int num : store) {
            if(!store.count(num-1)) {
                int curr = num;
                while(store.count(curr))
                    curr++;
                longestSeq = max(longestSeq, curr - num);
            }
        }
        return longestSeq;
    }
};
