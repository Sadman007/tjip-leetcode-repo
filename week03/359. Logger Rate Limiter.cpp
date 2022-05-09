//359 - Logger Rate Limiter
//Tc-0(n)
//Sc-0(1)
class Logger {
public:
    unordered_map<string, int> mp;
    long long  base = 10000007;
    Logger() {}
    long long getHash(const string &str)
    {
        int n = str.size();
        long long res = 0;
        for (int i = 0; i < n; ++i)
        {
            res = res * base + (int)str[i];
        }
        return res;
    }

    bool shouldPrintMessage(int timestamp, string message)
    {
        long long key = getHash(message);
        if (mp.count(key) && timestamp - mp[key] < 10)
        {
            return false;
        }
        mp[key] = timestamp;
        return true;
    }
};
