class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


	int sz=nums.size();

	map<int,int> visited;

	 for(int i=0;i<nums.size();i++)
        	{
		if(visited.count(target-nums[i])){
			return {i, visited[target-nums[i]]};
}
		
		visited[nums[i]]=i;
}
  
return {};
    }
};




