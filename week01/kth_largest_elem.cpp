// TC: O(N)
// MC: O(1)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Solution {
public:
    int partition(vector<int>& nums, int L, int R)
    {
        int pivot = nums[R];
        int i = L - 1;
        for(int j = L; j < R; j++)
        {
            if(nums[j] < pivot)
            {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[R]);
        return i + 1;
    }
    int kthSmallest(vector<int>& nums, int k)
    {
        int L = 0;
        int R = nums.size() - 1;
        while(L < R)
        {
            int pvt_idx = partition(nums, L, R);
            if(pvt_idx < k) L = pvt_idx + 1;
            else if(pvt_idx > k) R = pvt_idx - 1;
            else break;
        }
        return nums[k];
    }
    int findKthLargest(vector<int>& nums, int k) {
        shuffle(nums.begin(), nums.end(), rng);
        int n = nums.size();
        return kthSmallest(nums, n - k);
    }
};