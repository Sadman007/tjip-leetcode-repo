class Solution:
    def trap(self, height):
        left = 0
        right = len(height) -1
        
        left_max = 0
        right_max = 0
        total_water = 0
        
        while (left < right):
            left_max = max(left_max, height[left])
            right_max = max(right_max, height[right])
            
            if height[left] < height[right]:
                total_water += left_max - height[left]
                left += 1
                
            else:
                total_water += right_max - height[right]
                right-=1
                
        return total_water