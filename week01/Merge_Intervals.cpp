class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        int len = intervals.size();
        for(int i = 1; i < len; i++)
        {
            if( intervals[i-1][1] >= intervals[i][0])
            {
                intervals[i][0] = intervals[i-1][0];
                if(intervals[i][1] <= intervals[i-1][1])
                {
                    intervals[i][1] = intervals[i-1][1];
                }
            }
            else merged.push_back(intervals[i-1]);
        }
        merged.push_back(intervals[len - 1]);
        return merged;
    }
};
