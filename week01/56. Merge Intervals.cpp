class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>result;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(auto& i: intervals){
            if(i[0] >end){
                result.push_back({start, end});
                start = i[0];
                end = i[1];

            }
            else{
                end = max(end,i[1]);
            }

        }
        result.push_back({start,end});
        return result;
   }
};
