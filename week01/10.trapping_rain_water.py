#O(N) time | O(1) space
"""
1. if left < right then left++
2. if right < left or left == right then right--
"""

class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height)-1
        maxLeft = 0
        maxRight = 0
        total = 0
        
        while left < right:
            maxLeft = max(maxLeft, height[left])            
            maxRight = max(maxRight, height[right])
            
            if height[left] < height[right]:
                total += maxLeft - height[left]
                left += 1
            else:
                total += maxRight - height[right]
                right -= 1
        return total
                