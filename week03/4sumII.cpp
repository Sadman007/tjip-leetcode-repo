/**
Time: O(N * N), where N = length of each array.
Memory: O(N * N)
**/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int>ab;
        
        for(auto x : A)
        {
            for(auto y : B)
            {
                ab[x + y]++;
            }
        }
        
        int tupleCount = 0;
        
        for(auto x : C)
        {
            for(auto y : D)
            {
                if(ab.find(-(x + y)) != ab.end()) {
                    tupleCount += ab[-(x + y)];
                }
            }
        }
        
        return tupleCount;
    }
};