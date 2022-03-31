import heapq
class Solution:
    def minRooms(self, intervals):
        
        intervals.sort(key=lambda x: x[0])
        current_min_rooms = 0
        heap = []
        heapq.heappush(heap, intervals[0][1])
        current_min_rooms +=1
        max_min_rooms = 1

        for idx in range (1, len(intervals)):
            while len(heap) > 0:
                if  intervals[idx][0]   > heap[0]:
                    heapq.heappop(heap)
                    current_min_rooms -=1
                else:
                    break
            heapq.heappush(heap, intervals[idx][1])
            current_min_rooms +=1
            max_min_rooms = max(max_min_rooms, current_min_rooms)
        return max_min_rooms




            