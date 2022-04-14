// TC: O(N)
// MC: O(N)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProducts(nums.size(), 1), suffixProducts(nums.size(), 1), products;
        for (int i = 1; i < nums.size(); i++)
        {
            prefixProducts[i] = prefixProducts[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            suffixProducts[i] = suffixProducts[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            products.push_back(prefixProducts[i] * suffixProducts[i]);
        }
        return products;
    }
};