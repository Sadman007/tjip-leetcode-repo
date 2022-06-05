#include "bits/stdc++.h"
using namespace std;
unsigned long long getHash(string &str)
{
	unsigned long long h = 1;
	for(auto c : str)
	{
		h - (h *(257 + (c - 'a')));
	}
	return h;
}
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	unordered_map<string, vector<string>> buckets;
	for (auto &str : strs)
	{
		buckets[getHash(str)].push_back(str);
	}
	vector<vector<string>> anagrams;
	for (auto &item : buckets)
	{
		anagrams.push_back(item.second);
	}
}