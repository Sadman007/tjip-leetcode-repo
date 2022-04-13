#include "bits/stdc++.h"
using namespace std;
int trap(vector<int>& height)
{
	int L = 0, R = height.size() - 1, total_area = 0, L_mx = 0, R_mx = 0;
	while(L < R)
	{
		L_mx = max(L_mx, height[L]);
		R_mx  = max(R_mx, height[R]);
		if(height[L] < height[R])
		{
			total_area += L_mx - height[L];
			L++;
		}
		else
		{
			total_area += R_mx - height[R];
			R++;
		}
	}
	return total_area;
}
int main()
{
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1,4};
	cout << trap(height);
}