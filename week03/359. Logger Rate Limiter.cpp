#include<bits/stdc++.h>
using namespace std;
// TC = O(1)
// MC = O(N * S) where N = total number of queries, S = avg length of each message
class Logger{
public:
    unordered_map<string, int> groups;
    Logger(){
        groups.clear();
    }
    bool shouldPrintMessage(int timestamp, string message){
        if(groups.count(message) && groups[message] > timestamp){
            return false;
        }
        groups[message] = timestamp + 10; // current timestamp er sthe 10 add hbe...groups[message] er valuer sthe 10 add hbe na
        return true;
    }
};

int main()
{
    int t;
    cin>>t;
    Logger logger;
    while(t--){
        int timestamp;
        string message;
        cin>>timestamp>>message;
        cout<<logger.shouldPrintMessage(timestamp, message)<<endl;
    }
}

