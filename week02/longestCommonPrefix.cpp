#include <bits/stdc++.h>
using namespace std;
string findLCP(string &a, string &b)
{
	int idx = 0;
	while(a[idx] && b[idx] && a[idx] == b[idx])
	{
		idx++;
	}
	return a.substr(0,idx);
}
string longestCommonPrefix(vector<string>& strs)
{
	string lcp = strs[0];
	for(auto str : strs)
	{
		lcp = findLCP(lcp, str);
	}
	return lcp;
}