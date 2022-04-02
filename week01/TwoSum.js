/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
 var twoSum = function(nums, target) {
    
    let store = {}
    
     for (let i=0; i<nums.length ;i++ ){
        let remaining = target - nums[i];
       
       let keys = Object.keys(store);
        if(keys.includes(remaining.toString())){
       
         return [store[remaining] , i]
           
        }
       store[nums[i]] = i;

     } 
};