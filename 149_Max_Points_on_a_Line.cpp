//TC: O(N^2)
//MC: O(N)

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int mx = 0, BASE = 1000000007;
        for(int i = 0; i < (int)points.size(); i++){
            int Ax = points[i][0], Ay = points[i][1];
            unordered_map<long long, int> mp;
            for(int j = 0; j < (int)points.size(); j++){
                if(i == j) continue;
                int Bx = points[j][0], By = points[j][1];
                int dx = Ax - Bx, dy = Ay - By;
                int gcd = __gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;
                mx = max(mx, ++mp[dx*1LL*BASE + dy]);
            }
        }
        return mx+1;
    }
};
