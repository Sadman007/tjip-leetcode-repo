bool sortcol(vector<int> &v1, vector<int> &v2)
{
    return v1[0] < v2[0];
}
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), sortcol);
        int mx = 0, mn = INT_MAX;
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (i > 0 && intervals[i][0] > mx)
            {
                res.push_back({mn, mx});
                mn = INT_MAX;
            }
            mn = min(mn, intervals[i][0]);
            mx = max(mx, intervals[i][1]);
        }
        res.push_back({mn, mx});
        return res;
    }
};