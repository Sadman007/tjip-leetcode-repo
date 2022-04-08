class RandomizedSet
{
public:
    set<int> st;
    RandomizedSet()
    {
    }
    bool insert(int val)
    {
        if (st.count(val) == 0)
        {
            st.insert(val);
            return true;
        }
        return false;
    }
    bool remove(int val)
    {
        if (st.count(val))
        {
            st.erase(val);
            return true;
        }
        return false;
    }
    int getRandom()
    {
        auto it = st.begin();
        advance(it, rand() % st.size());
        return *it;
    }
};