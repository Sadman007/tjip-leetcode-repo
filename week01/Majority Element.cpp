//problem link:
//solve status:
//learnings:
#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	map<int, int> mapper;
    	int majority=0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		mapper[nums[i]]++;
    	}

    	// for(auto x: mapper){
    	// 	cout<<x.first<<" "<<x.second<<endl;
    	// }

    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if(mapper[nums[i]]>(nums.size()/2)){
    			majority= nums[i];
    			break;
    		}
    	}
    	return majority;
        
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
	std::vector<int> v= {2,2,1,1,1,2,2};
	cout<<a.majorityElement(v)<<endl;


	
    


        
}
