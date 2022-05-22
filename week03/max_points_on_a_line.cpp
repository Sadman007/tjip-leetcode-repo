/**
Time: O(N^2), where N = number of points.
Memory: O(N)
**/

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        map<pair<int, int>, int>slope_count;
        int maximum_points_on_a_line = 0;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            slope_count.clear();
            int duplicate_point = 0;
            for(int j = i + 1; j < n; j++) {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                // check if duplicate?
                if(dx == 0 && dy == 0) {
                    duplicate_point++;
                    continue;
                }
                int gcd = __gcd(dx, dy);
                // make dx, dy coprime for avoiding discrepancy
                dy /= gcd;
                dx /= gcd;
                auto dxy = make_pair(dx, dy);
                slope_count[dxy]++;
            }
            for(auto slope : slope_count) {
                int frequency = slope.second;
                maximum_points_on_a_line = max(maximum_points_on_a_line, frequency + duplicate_point);
            }
        }
        return maximum_points_on_a_line + 1;
    }
};

