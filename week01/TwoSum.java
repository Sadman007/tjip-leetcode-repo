public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> visited = new HashMap<>();

        for(int i = 0; i<nums.length; i++){
            int potentialValue = target - nums[i];
            if(visited.containsKey(potentialValue)){
                return new int[]{visited.get(potentialValue), i};
            }
            visited.put(nums[i], i);
        }
        return new int[0];
    }
