//problem link:https://leetcode.com/problems/two-sum/
//solve status: solved
//learnings: array,unordered Map

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        

        for (int i = 0; i < nums.size(); ++i)
        {
            int remaining = target - nums[i];
            if(seen.count(remaining)){
                return { seen[remaining],i};
            }

                seen[nums[i]]=i;

        }

        return {};


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
    std::vector<int> nums= {3,2,4}, res;
    int target =             6 ;

    res = a.twoSum(nums,target);


   cout<<"Output: ["<<res[0]<<","<<res[1]<<"]"<<endl;



        
}
