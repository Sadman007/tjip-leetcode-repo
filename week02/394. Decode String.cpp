// TC = O(N)
// MC = O(1)
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int> > charStore;
        charStore.push({"",0});
        int times = 0;
        for(auto ch: s){
            if(isdigit(ch)){
                times = (times * 10) + ch - '0';
            }
            else if(ch=='['){
                charStore.push({"",times});
                times = 0;
            }
            else if(ch == ']'){
                string str = charStore.top().first;
                int cnt = charStore.top().second;
                charStore.pop();
                while(cnt--){
                    charStore.top().first += str;
                }
            }
            else{
                charStore.top().first.push_back(ch);
            }
        }
        return charStore.top().first;
    }
};
