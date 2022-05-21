// TC = O(1)
// MC = O(1)
class DetectSquares {
public:
    map<pair<int,int>, int> points;

    DetectSquares() {
        points.clear();
    }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[{x,y}]++;
    }

    int count(vector<int> qpoint) {

        int total = 0;

        for(auto point: points){
            int x2 = qpoint[0];
            int y2 = qpoint[1];
            int x4 = point.first.first;
            int y4 = point.first.second;

            if(x2==x4 || (abs(x4-x2)!=abs(y4-y2))) continue;// x2=x4 means straight line

            if(points.count({x4,y2}) && points.count({x2,y4})){
                total += points[{x4,y2}] * points[{x2,y4}] * points[{x4,y4}];
            }
        }
        return total;
    }
};

/***********************************************/

// TC = O(1)
// MC = O(1)
class DetectSquares {
public:
    unordered_map<long long, int> points;
    int BASE = 1000000007;

    long long getSerializedValue(pair<int,int>p){
        return (1LL* p.first * BASE) + p.second;
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

        for(auto point: points){
            int x2 = qpoint[0];
            int y2 = qpoint[1];
            int x4 = point.first / BASE;
            int y4 = point.first % BASE;

            if(x2==x4 || (abs(x4-x2)!=abs(y4-y2))) continue;// x2=x4 means straight line

            if(points.count(getSerializedValue({x4,y2})) && points.count(getSerializedValue({x2,y4}))){
                total += points[getSerializedValue({x4,y2})] * points[getSerializedValue({x2,y4})] * points[getSerializedValue({x4,y4})];
            }
        }
        return total;
    }
};


