//TC: O(nlogn)
//MC: O(n)

class Solution {
public:
    int nthUglyNumber(int n) {
        int res = 1, cnt = 0;
        set<long long> st; st.insert(-1);
        priority_queue<long long> pq; pq.push(-1);

        while(cnt < n){
            res = -pq.top(); pq.pop();

            int sz = st.size();
            st.insert(res*-2LL);
            if(st.size() > sz) pq.push(res*-2LL);

            sz = st.size();
            st.insert(res*-3LL);
            if(st.size() > sz) pq.push(res*-3LL);

            sz = st.size();
            st.insert(res*-5LL);
            if(st.size() > sz) pq.push(res*-5LL);

            cnt++;
        }
        return res;
    }
};
