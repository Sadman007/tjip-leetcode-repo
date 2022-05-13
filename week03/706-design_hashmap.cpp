// TC - O(1)
// MC - O(n)
class MyHashMap
{
public:
    vector<int> hm;
    MyHashMap()
    {
        hm.resize(1e6 + 1, -1);
    }

    void put(int key, int value)
    {
        hm[key] = value;
    }

    int get(int key)
    {
        return hm[key];
    }

    void remove(int key)
    {
        hm[key] = -1;
    }
};
