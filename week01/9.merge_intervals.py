#O(N) time | O(N) space

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key= lambda x: x[0])
        i=0
        while i < len(intervals)-1:
            leftMax = max(intervals[i][0], intervals[i+1][0])
            rightMax = min(intervals[i][1], intervals[i+1][1])
            
            if leftMax <= rightMax:
                intervals[i] = [min(intervals[i][0], intervals[i+1][0]), max(intervals[i][1], intervals[i+1][1])]
                del intervals[i+1]
            else:
                i += 1
        return intervals