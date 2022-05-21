// TC = O(N^2)
// MC = O(N)
// https://youtu.be/IQKIm0wEu4w
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

/***************************************************/

// given TLE
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int len = points.size();
        int minArea = INT_MAX/2;

        for(int i=0;i<len;i++){
            int x4 = points[i][0];
            int y4 = points[i][1];

            // cout<<"x4 = "<<x4<<" "<<"y4 = "<<y4<<"----\n";

            for(int j=0;j<len;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(x2==x4) continue;
                // cout<<"x2 = "<<x2<<" "<<"y2 = "<<y2<<"++++\n";

                for(int k=0;k<len;k++){
                    // points[k][1] = y2, points[k][0] = x4
                    if(points[k][1]==y4 || points[k][0]==x2) continue;

                    if(points[k][1]==y2 && points[k][0]==x4){
                        int third_x = points[k][0];
                        int third_y = points[k][1];

                        // cout<<"third_x = "<<third_x<<" "<<"third_y = "<<third_y<<"^^^^\n";
                        for(int m = 0;m<len;m++){

                            if(points[m][1]==y2 || points[m][0]==x4 ||
                              points[m][1]==third_y || points[m][0]==third_x) continue;

                            if(points[m][0]==x2 && points[m][1]==y4){
                                int fourth_x = points[m][0];
                                int fourth_y = points[m][1];
                                // cout<<"fourth_x = "<<fourth_x<<" "<<"fourth_y = "<<fourth_y<<"****\n";
                                minArea = min(minArea,abs(fourth_x-x4)*abs(fourth_y-y2));
                            }
                        }
                    }

                }
            }
        }
        return minArea==INT_MAX/2? 0:minArea;
    }
};
