class Solution {
public:
    int longestConsecutive(vector<int>& A) {
        
    if(A.size() == 0)
    {
        return 0;
    }
    map<int,int>mp;
    for(auto it : A)
    {
        ++mp[it];
    }

    int mx = -1;
    vector<int>temp;
    for(auto it: mp)
    {
        temp.push_back(it.first);
    }

    int cnt = 1;
    for(int i=1; i<temp.size(); i++)
    {
        if(temp[i]-temp[i-1] == 1)
        {
            cnt++;
        }
        else
        {
            mx = max(cnt,mx);
            cnt = 1;
        }
    }

    mx = max(mx,cnt);

    return mx;
    }
};
