// TC: O(N * N), where N = length of each array.
// MC: O(N * N)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> ab;
        int tuples = 0;
        for(auto a: nums1){
            for(auto b:nums2){
                ab[a+b]++;
            }
        }
        for(auto c:nums3){
            for(auto d:nums4){
                if(ab.count(-c-d)){
                    tuples += ab[-c-d];
                }
            }
        }
        return tuples;
    }
};
