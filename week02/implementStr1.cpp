#include "bits/stdc++.h"
using namespace std;
vector<int>  prefixHashHaystack;
int base = 29;
int MOD  = 1000000007;
void preprocess(string &haystack)
{
	prefixHashHaystack[0] = haystack[0];
	for(int i = 1; i < haystack.size(); i++)
	{
		prefixHashHaystack[i] = (prefixHashHaystack[i - 1] * base) % MOD;
		prefixHashHaystack[i] += haystack[i];
		po[i] = (po[i - 1] * base) % MOD;
	}
}
long long getRangeHash(int L, int R)
{
	long long x1 = prefixHashHaystack[R];
	long long x2 = L == 0 ? 0 : (prefixHashHaystack[L - 1] * po[R - L + 1]) % MOD;
	return (x1 - x2 + MOD) % MOD ;
}
long long generateHash(string &str)
{
	long long h = 0;
	for(auto s : str)
	{
		h = (h * base) + s;
		h %= MOD;
	}
	return h;
}
int strStr(string haystack, string needle)
{
	int lb = needle.size();
	int la = haystack.size();
	prefixHashHaystack.resize(la + 1, 0);
	preprocess(haystack);
	long long needleHash = generateHash(needle);
	for(int i = 0; i <= (la -lb); i++)
	{
		if(getRangeHash(i, i + lb - 1) == needleHash)
		{
			return i;
		}
	}
	return -1;
}