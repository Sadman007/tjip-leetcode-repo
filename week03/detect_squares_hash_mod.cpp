class DetectSquares {
public:
    map<long long, int> points;
    int base = 1000000007;
    DetectSquares() {
        points.clear();
    }

    long long getSerializedValue(pair<int,int> p) {
        return (1LL * p.first * base) + p.second;
    }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[getSerializedValue({x,y})]++;
    }

    int count(vector<int> qpoint) {
        int total = 0;
        for(auto point: points) {
            int x2 = qpoint[0];
            int y2 = qpoint[1];
            int x4 = point.first/base;
            int y4 = point.first%base;
            if(x2 == x4 || (abs(x2-x4) != abs(y2-y4))) continue;
            if(points.count(getSerializedValue({x2,y4})) && points.count(getSerializedValue({x4,y2}))){
                total += points[getSerializedValue({x2,y4})] * points[getSerializedValue({x4,y2})] * point.second;
            }
        }
        return total;
    }
};
