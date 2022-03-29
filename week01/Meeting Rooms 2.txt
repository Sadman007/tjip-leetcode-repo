/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
 
        if(intervals.size()==0)
            return 0;
        vector<int> St ;
        vector<int> End ;
        for(Interval i : intervals){
            St.push_back(i.start);
            End.push_back(i.end);
        }
        sort(St.begin(),St.end());
        sort(End.begin(),End.end());
        int roomCount=0, stIndex=0, endIndex=0;
 
        while(stIndex< intervals.size()){
 
            if(St[stIndex] >= End[endIndex]){
 
                roomCount-=1;
                endIndex+=1;
            }
            stIndex+=1;
            roomCount+=1;
     
        }
        return roomCount;
 
 
    }
};
