class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        	int sz=nums.size();
	int ind=0;
	for( int i = 0;  i <  sz ; i++) {
		
		if(nums[i] != 0){

			nums[ind]= nums[i];
			ind += 1;
		}
}

while(ind < sz){

	nums[ind] =0;
	ind += 1;
}
	
	
	
    }
};


