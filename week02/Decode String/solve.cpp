class Solution {
public:
    string decodeString(string s) {
        int len = s.length();
        if(len <=3 ) return s;
        stack<string>st;
        string temp = "";
        string ans = "";
        for(auto ch : s)
        {
            if(ch != ']')
            {
                temp = temp+ch;
                st.push(temp);
                temp = "";
            }     
            else
            {
                if(!st.empty())
                {
                    temp = "";
                    while(st.top() != "[")
                    {
                        temp = st.top() + temp;
                        st.pop();
                    }
                    st.pop();
                    string integer = "";
                    while(st.size()>0 and (st.top()>="0" and st.top()<="9"))
                    {
                        integer = st.top() + integer;
                        st.pop();
                    }
                    stringstream ss(integer);
                    int turn = 0;
                    ss>>turn;
                    string unit = temp;
                    temp = "";
                    while(turn--)
                    {
                        temp += unit;
                    }
                    st.push(temp);
                    temp = "";
                }
            }
        }
        while(st.size()>=1)
        {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;  
    }
};
