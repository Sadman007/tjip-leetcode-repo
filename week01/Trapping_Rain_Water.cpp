class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size() - 1, area = 0, Lmx = 0, Rmx = 0;
        while(L < R) {
            Rmx = max(Rmx, height[R]);
            Lmx = max(Lmx, height[L]);
            
            if (height[L] <= height[R]) {
                area += (Lmx - height[L]);
                L++;
            }
            else {
                area += (Rmx - height[R]);
                R--;
            }
        }
        return area;
    }
};
