Solution:

class RandomizedSet {
    
    Set<Integer> randomizedSet;

    public RandomizedSet() {
        this.randomizedSet = new HashSet<Integer>();
    }
    
    public boolean insert(int val) {
        if(this.randomizedSet.contains(val)) return false;
        else {
            this.randomizedSet.add(val);
            return true;
        }
    }
    
    public boolean remove(int val) {
        if(this.randomizedSet.contains(val)) {
            this.randomizedSet.remove(val);
            return true;
        }
        return false;
    }
    
    public int getRandom() {
         Random rand = new Random(); 
         int upperbound =  this.randomizedSet.size();
         int int_random = rand.nextInt(upperbound);
         List<Integer> convertSetToList = new ArrayList(this.randomizedSet);
         return convertSetToList.get(int_random);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
***Learning