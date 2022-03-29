public int majorityElement(int[] nums) {
        int voteCount = 1;
        int winner = nums[0];
        for(int i=1; i<nums.length; i++){
            if(nums[i] != winner){
                voteCount--;                                      
                if(voteCount == -1){
                  winner= nums[i];
                    voteCount = 1;
                } 
            }else voteCount++;
        }
        return winner;
    }
