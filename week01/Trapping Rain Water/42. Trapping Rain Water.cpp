

//Second Approach
//Time => O(n)
//Space => O(1)


class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size()<3) return 0;
        int lp = 1;
        int rp = height.size()-2;
        int maxLeft = height[0];
        int maxRight = height[height.size()-1];
        int TPcount = 0;
        while(lp <= rp)
        {
            if(maxLeft<=maxRight)
            {
                if(height[lp]>=maxLeft)
                {
                    maxLeft = height[lp];
                }
                else
                {
                    TPcount += maxLeft-height[lp];
                }
                lp++;
            }
            else
            {
                if(height[rp]>=maxRight)
                {
                    maxRight = height[rp];
                }
                else
                {
                    TPcount += maxRight-height[rp];
                }
                rp--;
            }
        }
        return TPcount;
    }
};
