//Time complexity - 0(n)
//space complexity - 0(n)
class Solution {
public:
    string decodeString(string s) {
        int num = 0;
        stack<pair<string , int >> st;
        st.push({"",1});

        for(auto ch : s){
          if(isdigit(ch))  {
            num = num * 10 + (ch - '0');
          }

          else if(ch == '['){
             st.push({"",num});
             num = 0;
          }

           else if(ch == ']'){

              string str = st.top().first;
              int k = st.top().second;
              st.pop();

              while(k--){
                  st.top().first += str;
              }
          }

          else
              st.top().first.push_back(ch);

        }

        return st.top().first;
    }
};
