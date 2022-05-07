class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int hlen = haystack.size(), nlen = needle.size();
        for (int i = 0; i <= hlen - nlen; i++)
        {
            if (haystack.substr(i, nlen) == needle)
                return i;
        }
        return -1;
    }
};