// TC  : O ( K + (N-K) logK) )
// Space : O(K) [ size of heap];
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

	priority_queue<int > pq;
	int ind=0;
	int sz=nums.size();
	while( ind < sz){

		pq.push( -nums[ind]);
		if(pq.size() > k)
			pq.pop();

ind+=1;
	}
	
	return -pq.top();
        
    }
};




// TC : O(N) [ N : size of array ] 
// SC : O(1)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        shuffle(nums.begin(), nums.end(), rng);
        return quickSelect(nums,nums.size()-1, nums.size()-k);
        
        
    }
    
    int quickSelect(vector<int> & nums, int sz, int k){
        
        if(nums.size()==1)
            return nums[0];
        int l=0, r=sz;
        
        while(l<=r){
            int position = partition(nums, l, r);
             if(position < k ){
                // search on right
                l=position+1;
                
            }
            // search on left
            else if(position>k){
                r=position-1;
            }
            else break;
            
        }
        return nums[k];
            

    }
    int partition(vector<int> & nums, int l, int  r){
        
        int pivot= nums[r];
        int i=l;
        for(int j=l;j<r;j++){
            
            if(nums[j]<pivot){
                swap(nums[j], nums[i]);
                i++;
                
            }
        }
        swap(nums[i],nums[r]);
        return i;
        
    }
};
