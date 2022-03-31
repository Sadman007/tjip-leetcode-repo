class Solution:
    def fourSum(self, nums, target):
            
            result  = set()
            nums.sort()
            
            for idx1 in range (0, len(nums)-3):
                for idx2 in range (idx1+1, len(nums)-2):
                    
                    idx3 = idx2+1
                    idx4 = len(nums)-1
                    
                    while (idx3 < idx4):
                        if nums[idx1] + nums[idx2] + nums[idx3] + nums[idx4] == target:
                            result.add(( nums[idx1], nums[idx2], nums[idx3], nums[idx4]))
                            idx3+=1
                            idx4-=1
                        elif  nums[idx1] + nums[idx2] + nums[idx3] + nums[idx4] < target:
                            idx3 +=1    
                        else:
                            idx4 -=1
                            
            return list(result)