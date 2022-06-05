#include "bits/stdc++.h"
using namespace std;
int strStr(string haystack, string needle)
 {
 	int lengthA = haystack.size();
 	int lengthB = needle.size();
 	for(int i = 0; i <= (lengthA - lengthB); i++)
 	{
 		if(haystack.substr(i, lengthB) == needle)
 		{
 			return i;
 		}
 	}
 	return -1;
 }
