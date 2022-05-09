// TC - O(n)
// MC - O()
class DetectSquares
{
public:
    unordered_map<long long, int> points;
    int BASE = 1000000007;
    long long getValue(pair<int, int> p)
    {
        return (1LL * p.first * BASE) + p.second;
    }
    DetectSquares()
    {
        points.clear();
    }

    void add(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        points[getValue({x, y})]++;
    }

    int count(vector<int> qpoint)
    {
        int total = 0;

        for (auto point : points)
        {
            int x2 = qpoint[0];
            int y2 = qpoint[1];
            int x4 = point.first / BASE;
            int y4 = point.first % BASE;

            if (x2 == x4 || (abs(x2 - x4) != abs(y2 - y4)))
                continue;
            if (points.count(getValue({x4, y2})) && points.count(getValue({x2, y4})))
            {
                total += points[getValue({x4, y2})] * points[getValue({x2, y4})] * point.second;
            }
        }
        return total;
    }
};

// TC - O(n)
// MC - O()
class DetectSquares
{
public:
    map<pair<int, int>, int> points;
    DetectSquares()
    {
        points.clear();
    }

    void add(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        points[{x, y}]++;
    }

    int count(vector<int> qpoint)
    {
        int total = 0;

        for (auto point : points)
        {
            int x2 = qpoint[0];
            int y2 = qpoint[1];
            int x4 = point.first.first;
            int y4 = point.first.second;

            if (x2 == x4 || (abs(x2 - x4) != abs(y2 - y4)))
                continue;
            if (points.count({x4, y2}) && points.count({x2, y4}))
            {
                total += points[{x4, y2}] * points[{x2, y4}] * point.second;
            }
        }
        return total;
    }
};