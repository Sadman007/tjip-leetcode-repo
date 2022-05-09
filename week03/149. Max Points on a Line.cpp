//149. Max Points on a Line
//Tc--0(n*n)
//Sc--0(n)
class Solution {
public:
    int gcd(int a, int b) {
        if(a==0) return b;
        return gcd(b%a, a);
    }
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        if(points.size()<=2) return points.size();

        for (int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> m;
            int duplicate = 1;

            for (int j = i + 1; j < points.size(); ++j) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 && y1 == y2) {
                    duplicate++;
                    continue;
                }

                int dx = x2 - x1;
                int dy = y2 - y1;
                int d = gcd(dx, dy);
                m[{dx / d, dy / d}]++;
            }
            res = max(res, duplicate);
            for (auto it = m.begin(); it != m.end(); it++)
            {
                res = max(res, it->second + duplicate);
            }
        }
        return res;
    }

};
