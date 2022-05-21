// TC: O(N)
// MC: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currentElected = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) currentElected = num;
            if (currentElected == num) count++;
            else count--;
        }
        return currentElected;
    }
};