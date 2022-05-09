//2013. Detect Squares
//Tc : 0(n)
//sc : 0(logn)
class DetectSquares {
public:
    unordered_map<long long, int > points;
    int Base = 10000007;
    long long getSerializedValue(pair<int,int> p){
        return (1LL * p.first * Base) + p.second;
    }
    DetectSquares() {
        points.clear();
    }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[getSerializedValue({x,y})]++;
    }

    int count(vector<int> qpoint) {
        int total = 0;
        for(auto point : points){
            int x2 = qpoint[0];
            int y2 = qpoint[1];
            int x4 = point.first / Base;
            int y4 = point.first % Base;

            if(x2 == x4 || (abs(x2 - x4) != abs(y2 - y4)))continue;
            if(points.count(getSerializedValue({x4,y2})) && points.count(getSerializedValue({x2,y4}))){
                total += points[getSerializedValue({x4,y2})] * points[getSerializedValue({x2,y4})] * point.second;
            }
        }
        return total;

    }
};
