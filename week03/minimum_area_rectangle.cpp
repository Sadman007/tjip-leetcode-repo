/**
Time: O(N^1.5) on avg, O(N^2) in worst case, where N = total number of points.
Memory: O(N) where N = total number of points
**/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> x2y;
        int res = INT_MAX;
        for (auto &p : points) {
            x2y[p[0]].insert(p[1]);
        }
        for (auto i = x2y.begin(); i != x2y.end(); i++) {
            for (auto j = next(i); j != x2y.end(); j++) {
                if (i->second.size() < 2 || j -> second.size() < 2) {
                    continue;
                }
                vector<int> ys;
                set_intersection(begin(i->second), end(i->second),
                                 begin(j->second), end(j->second),
                                back_inserter(ys));
                for (int k = 1; k < ys.size(); k++) {
                    res = min(res, abs(j->first - i->first) * (ys[k] - ys[k - 1]));
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};