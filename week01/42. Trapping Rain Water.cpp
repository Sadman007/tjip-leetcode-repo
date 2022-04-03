// T - O(n), M - O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size()-1, L_mx = 0, R_mx = 0, total_area = 0;
        while(L<R){
            L_mx = max(height[L],L_mx);
            R_mx = max(height[R],R_mx);

            if(height[L]<height[R]){
                total_area += L_mx - height[L];
                L++;
            }
            else{
                total_area += R_mx - height[R];
                R--;
            }
        }
        return total_area;
    }
};
