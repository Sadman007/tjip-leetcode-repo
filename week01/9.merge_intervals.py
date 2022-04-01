#O(N) time | O(N) space
"""
description: If both ranges have at least one common point, then we say that they’re overlapping. In other words, we say that two ranges {[L_1, R_1]} and \{[L_2, R_2]} are overlapping if: {max(L_1, L_2) <= min(R_1, R_2)}
On the other hand, non-overlapping ranges don’t have any points in common.
"""

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