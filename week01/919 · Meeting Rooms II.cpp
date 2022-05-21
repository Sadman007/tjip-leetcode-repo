// T - O(nlogn), M - O(logn)
class Solution {
public:

    int minMeetingRooms(vector<Interval> &intervals) {
        vector<int> startTime,endTime;
        for(auto interval:intervals){
            startTime.push_back(interval.start);
            endTime.push_back(interval.end);
        }
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());

        int startP = 0, endP = 0, len = intervals.size();
        int roomReq = 0, mx = 0;
        while(startP<len && endP<len){

            if(startTime[startP] < endTime[endP]){
                startP++;
                roomReq++;
            }
            else{
                endP++;
                roomReq--;
            }
            mx = max(mx,roomReq);
        }
        return mx;
    }
};
