// T - O(nlogn), M - O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());// start-wise sort hbe
        int len = intervals.size();
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i=1;i<len;i++){
            int n = result.size();

            if(intervals[i][0]>result[n-1][1]){
                result.push_back(intervals[i]);
            }
            else{
                int end = max(result[n-1][1],intervals[i][1]);
                result[n-1][1] = end;
            }
        }
        return result;
    }
};
