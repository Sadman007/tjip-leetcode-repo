/**
Time: O(N) per query, where N = total number of points before each query.
Memory: O(N)
**/

class DetectSquares {
public:
    unordered_map<long long, int> points;
    int BASE = 1000000007;
    long long getSerializedValue(pair<int, int>p) {
        return (1LL * p.first * BASE) + p.second;
    }
    
    DetectSquares() {
        points.clear();
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[getSerializedValue({x, y})]++;
    }
    
    int count(vector<int> qpoint) {
        int total = 0;
        
        for (auto point : points) {
            /**
            (x4y2) ------ (x2y2)
            |
            |
            |
            |
            |
            |
            (x4y4) ------ (x2y4)
            **/
            // key = point.first = pair<int, int>
            // value = point.second = int
            
            // x = key.first = point.first.first
            // y = key.second
            // freq = value
            int x2 = qpoint[0];
            int y2 = qpoint[1];
            int x4 = point.first / BASE;
            int y4 = point.first % BASE;
            
            if (x2 == x4 || (abs(x2 - x4) != abs(y2 - y4))) continue;
            
            if (points.count(getSerializedValue({x4, y2})) && points.count(getSerializedValue({x2, y4}))) {
                total += points[getSerializedValue({x4, y2})] * points[getSerializedValue({x2, y4})] * point.second;
            }
        }
        
        return total;
    }
};