// TC: O(N)
// MC: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;
        
        int max_L = 0, max_R = 0, total_Area = 0;
        
        while(L<R){
            max_L = max(max_L, height[L]);
            max_R = max(max_R, height[R]);
            
            if(height[L] < height[R]){
                total_Area +=  max_L - height[L];
                L++;
            }
            else{
                total_Area += max_R - height[R];
                R--;
            }
            
        }
        return total_Area;
    }
};