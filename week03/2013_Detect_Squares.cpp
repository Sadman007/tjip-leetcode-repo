//TC: O(Q*N)  -> N := total points
//MC: O(N)

class DetectSquares {
public:
    unordered_map<long long, int> all_points;
    long long BASE = 1000000007;
    DetectSquares() {
        all_points.clear();
    }

    void add(vector<int> point) {
        all_points[(BASE*point[0]) + point[1]]++;
    }

    int count(vector<int> qpoint) {
        int Ax = qpoint[0], Ay = qpoint[1], res = 0;
        //cout<<point.size()<<endl;
        for(auto p : all_points){
            int Cx = p.first/BASE, Cy = p.first%BASE;
            int Bx = Cx, By = Ay;
            int Dx = Ax, Dy = Cy;
            int len = abs(Ax - Bx), width = abs(Ay - Dy);
            if(len != width || len == 0) continue;
            if(all_points.count((Bx*BASE) + By) && all_points.count((Dx*BASE) + Dy)){
                res += (all_points[(Cx*BASE) + Cy] * all_points[(Bx*BASE) + By] * all_points[(Dx*BASE) + Dy]);
            }
        }
        return res;
    }
};

