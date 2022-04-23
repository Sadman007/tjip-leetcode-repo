// TC: O(N)
// MC: O(N)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int>calendar;
        for(auto it : intervals)
        {
            int st = it[0];
            int en = it[1];
            calendar[st]++;
            calendar[en]--;
        }
        int cnt = 0, mxRoom = 0;
        for(auto it : calendar)
        {
            cnt += it.second;
            mxRoom = max(mxRoom, cnt);
        }
        return mxRoom;
    }
};