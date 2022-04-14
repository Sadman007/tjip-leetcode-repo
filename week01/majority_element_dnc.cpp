// TC: O(NlogN)
// MC: O(N)
class Solution {
public:
    vector<int> findMajorityElements(vector<int>& nums, int L, int R) {
        if (L == R) return {nums[L]};
        int M = L + (R - L) / 2;
        vector<int> fromLeft = findMajorityElements(nums, L, M);
        vector<int> fromRight = findMajorityElements(nums, M + 1, R);
        vector<int> result, ans;
        unordered_set<int> bucket(fromRight.begin(), fromRight.end());
        for (auto number : fromLeft) {
            if (bucket.count(number) == 0) {
                result.push_back(number);
            }
        }
        for (auto number : fromRight) {
            result.push_back(number);
        }
        for (auto number : result) {
            int cnt = 0;
            for (int i = L; i <= R; i++) {
                if (nums[i] == number)
                    cnt++;
            }
            if (cnt > (R - L + 1) / 2) {
                ans.push_back(number);
            }
        }
        return ans;
    }
    int majorityElement(vector<int>& nums) {
        return findMajorityElements(nums, 0, nums.size() - 1)[0];
    }
};