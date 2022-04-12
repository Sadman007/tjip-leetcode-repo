/**
 * @param {number[]} nums
 * @return {number}
 */
 var singleNumber = function(nums) {
    const store = {};
    for(let i = 0 ; i < nums.length ; i++){
        if(store[nums[i]]){
            delete store[nums[i]];
        }else{
            store[nums[i]] = 1;
        }
    }  
    return Object.keys(store)[0];
  };