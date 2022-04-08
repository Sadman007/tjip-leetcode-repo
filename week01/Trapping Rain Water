class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size()==0)
            return 0;
        int leftMax=0, rightMax=0;
        int l=0,r=height.size()-1;
        int totalArea=0;
        while(l<r){
            if(height[l]>leftMax) 
                leftMax=height[l];
            if(height[r]>rightMax) 
                rightMax=height[r];
            if(leftMax<rightMax){
                totalArea+=(leftMax-height[l]);
                l+=1;
                
            }
            else {
                totalArea+=(rightMax-height[r]);
                r--;
            }
        }
        
        return totalArea;
        
    }
};
