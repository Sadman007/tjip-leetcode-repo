// TC = O(N^2)
// MC = O(N)
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int len = points.size();
        int minArea = INT_MAX/2;

        set<pair<int,int> > visited;

        for(int i=0;i<len;i++){
            int x2 = points[i][0];
            int y2 = points[i][1];
            for(auto point:visited){
                int x4 = point.first;
                int y4 = point.second;
                if(visited.count({x4,y2}) && visited.count({x2,y4})){
                    minArea = min(minArea,abs(x4-x2)*abs(y4-y2));
                }
            }
            visited.insert({x2,y2});
        }
        return minArea==INT_MAX/2? 0:minArea;
    }
};
// https://youtu.be/IQKIm0wEu4w
/***************************************************/
