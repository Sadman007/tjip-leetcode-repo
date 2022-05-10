//TC: O(N^2)
//MC: O(N)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int area = INT_MAX, sz = points.size();
        unordered_map<int, unordered_set<int> > mp;
        for(auto it : points){
            mp[it[0]].insert(it[1]);
        }

        for(int i = 0; i < sz; i++){
            int ax = points[i][0], ay = points[i][1];
            for(int j = i+1; j < sz; j++){
                int cx = points[j][0], cy = points[j][1];
                if(ax == cx || ay == cy) continue;
                if(mp[cx].find(ay) == mp[cx].end() || mp[ax].find(cy) == mp[ax].end()) continue;

                int len = abs(ax - cx);
                int width = abs(ay - cy);
                area = min(area, len*width);
            }
        }
        return area == INT_MAX ? 0 : area;
    }
};
