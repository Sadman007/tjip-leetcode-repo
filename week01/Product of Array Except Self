class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
vector<int> res;
	res.resize(nums.size());
	res[0]=1;
	for(int i=1;i<nums.size();i++)
		res[i]=res[i-1]*nums[i-1];
	
	int right=1;
	for(int i=nums.size()-1;i>=0;i–)
	{
	res[i]=res[i]*right;
	right*=nums[i];
}
return res;
    }
};

/*

nums=[1,2,3,4]
res[0]=1;
res[1]=res[0]* nums[0]=1;
res[2]=res[1]* nums[1]=2;
res[3]=6;

res[3]=6;
right=1*4;
res[2]= res[2]*4= 2*4 = 8;
res[1]=res[1]*12=12;
res[0]=res[0]*24;

*/
