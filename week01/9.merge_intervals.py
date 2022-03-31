class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        result = []
        intervals.sort(key=lambda x: x[0])
        start  = intervals[0][0]
        end = intervals[0][1]
        for idx in range (1, len(intervals)):

            if intervals[idx][0] <=  end:
                end = intervals[idx][1]  if intervals[idx][1] > end else end
            else: 
                result.append([start, end])
                start = intervals[idx][0]
                end = intervals[idx][1] 
        result.append([start, end])     
        return result