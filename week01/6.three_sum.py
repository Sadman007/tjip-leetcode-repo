
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        result = set()
        nums.sort()
        
        for  idx in range (0, len(nums)-2):
            first = idx
            
            second =  first+1
            third = len(nums)-1
            while second < third:
                if nums[first] + nums[second] + nums[third] == 0:
                    result.add((nums[first] , nums[second] , nums[third]))
                    second  +=1
                    third -=1
                    
                            
                elif nums[first] + nums[second] + nums[third] <= 0:
                    second +=1
                else:
                    third -=1
                    
                    
                        
                    
        return list(result)

            