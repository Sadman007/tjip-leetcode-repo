//939. Minimum Area Rectangle
//Tc-0(nx * ny)
//Sc-0(n)
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
      unordered_map<int, set<int>>x2y;
      for(auto &p : points){
             x2y[p[0]].insert(p[1]);
      }
      int res = INT_MAX;
      for(auto i = x2y.begin(); i != x2y.end(); i++)
      {
          for(auto j = next(i) ; j != x2y.end(); j++)
             {
                if(i->second.size() < 2 || j->second.size() < 2) continue;
                vector<int> intersect_points;
                set_intersection(begin(i->second), end(i->second),
                                begin(j->second), end(j->second) , back_inserter(intersect_points));

                for(int k = 1; k < intersect_points.size(); k++){

                       int area = abs(j->first - i->first) * abs(intersect_points[k] - intersect_points[k-1]);
                       res = min(res, area);
                }
            }
      }
      if(res == INT_MAX) res = 0;
      return res;

    }

};

/*
//Tc-0(n^2)
//Sc-0(n)
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>>x2y;
        for(auto &p : points){
             x2y[p[0]].insert(p[1]);
        }

        int res = INT_MAX;
        int n = points.size();
        for(int i = 0; i < n ; i++)
        {
           for(int j = i + 1; j<n; j++){
               int x1 = points[i][0];
               int y1 = points[i][1];
               int x2 = points[j][0];
               int y2 = points[j][1];

               if(x1 != x2 && y1 !=y2){
                   if(x2y[x1].count(y2) && x2y[x2].count(y1)){
                       int area = abs(x1 - x2) * abs(y1 - y2);
                       res = min(res, area);}
               }
           }
       }
      if(res == INT_MAX) res = 0;
      return res;

    }

};
*/
