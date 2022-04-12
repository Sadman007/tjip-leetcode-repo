//problem link: https://leetcode.com/problems/kth-largest-element-in-an-array/
//solve status: solved
//learnings:
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	Solution a;
	std::vector<int> v= {3,2,3,1,2,4,5,5,6};
	cout<<a.findKthLargest(v,4)<<endl;


	
    


        
}
