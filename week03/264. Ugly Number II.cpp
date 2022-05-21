// TC = O(logn)
// MC = O(n)
class Solution {
public:
    vector<long long> ugly;
    unordered_map<long long ,bool> visited;

    void gen(long long x){
        if(x>2000000000000) return;
        if(visited.find(x)!=visited.end()) return;
        visited[x] = true;
        ugly.push_back(x);

        gen(2*x);
        gen(3*x);
        gen(5*x);

    }
    int nthUglyNumber(int n) {
        gen(1LL);
        sort(ugly.begin(),ugly.end());
        return ugly[n-1];
    }
};
