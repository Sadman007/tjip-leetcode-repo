from typing import (
    List,
)
from lintcode import (
    Interval,
)

"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end  
"""
#Complexity: O(NlogN) time | O(N) space

class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: the minimum number of conference rooms required
    """
    def min_meeting_rooms(self, intervals: List[Interval]) -> int:
        # Write your code here
        roomCount = 0
        maxRooms = 0
        start = end = []
        start = sorted([i.start for i in intervals])
        end = sorted([i.end for i in intervals])
        i = j = 0
        while i < len(start) and j < len(end):
            if start[i] < end[j]:
                roomCount += 1
                i += 1
            else:
                j += 1
                roomCount -= 1
            maxRooms = max(maxRooms, roomCount)
        return maxRooms