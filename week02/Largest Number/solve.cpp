bool static compare(string a,string b)
{    
        return (a+b)>(b+a);
}
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        
        vector<string>temp;
        for(auto s : nums)
        {
            temp.push_back(to_string(s));
        }
        sort(temp.begin(),temp.end(),compare);
        string ans = "";
        for(auto i : temp)
        {
            ans += i;
        }
        while(ans[0] == '0' and ans.length()>1)
        {
            ans.erase(0,1);
        }
        
        return ans;
        
    }
};
