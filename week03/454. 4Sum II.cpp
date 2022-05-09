//454. 4Sum II
//Tc-0(n*2)
//sc-0(n*2)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> sum1,sum2;
    int res = 0;
    int n = nums1.size();
    for (int  i = 0; i< n ; i++)
    {
      for (int j =0; j<n ; j++)
      {
         sum1[nums1[i] + nums2[j]]++;
         sum2[nums3[i] + nums4[j]]++;
      }
    }

    for (auto a : sum1) res += a.second * sum2[-a.first];
    return res;
    }
};
