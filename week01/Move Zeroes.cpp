//problem link:
//solve status:
//learnings:
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
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int vec_size = nums.size();
        int swaped = -1, index = 0;
        while(index < vec_size )
        {
            if(nums[index] != 0)
            {
                swaped++;
                swap(nums[swaped], nums[index]);
            }
            index++;
        }



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
	std::vector<int> v={0,1,2,3,4};
	a.moveZeroes(v);
	//cout<<a.func()<<endl;


	
    


        
}


   //  	int counter=0,index = 0;

   //  int vec_size = nums.size();

   //  while(index<vec_size+1 && !nums.empty()){

   //    if (nums[index] == 0)
   //    {
   //      nums.erase(nums.begin() + index);
   //      counter++;
   //      index = 0;
   //    }
   //    else{
   //      index++;
   //    }


   //  }

   //  	for (int i = 0; i < counter; ++i)
   //  	{
   //  		nums.push_back(0);
   //  	}

   // for(auto x: nums){
   // 	cout<<x<<endl;
   // }