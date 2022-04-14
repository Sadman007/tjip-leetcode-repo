class Solution {
public:
    int trap(vector<int>& height) {
        int l,r,j,sum=0,lmax=INT_MIN,rmax=INT_MIN;
        l=0,r=height.size()-1;
        while(l<r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            
            if(height[r]>height[l]){
                l++;
                sum+=((lmax-height[l]<0)?0:lmax-height[l]);
            }
            else{
                r--;
                sum+=((rmax-height[r]<0)?0:rmax-height[r]);
            }
            
        }
        return sum;
    }
};