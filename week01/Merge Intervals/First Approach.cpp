class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>&vc) {
        if(vc.size() == 1) return vc;
        vc.push_back({100000,100000});
        vector< vector<int>>ans;
        sort(vc.begin(),vc.end());
        int first = vc[0][0];
        int second = vc[0][1];
        for(int i=1; i<vc.size(); i++)
        {
            if(second>=vc[i][0] and vc[i][1] >= second)
            {
                second = vc[i][1];
            }
            else if(second>=vc[i][0] and vc[i][1] < second)
            {
                continue;
            }
            else
            {
                ans.push_back({first,second});
                first = vc[i][0];
                second = vc[i][1];
            }
        }
        return ans;   
    }
};
