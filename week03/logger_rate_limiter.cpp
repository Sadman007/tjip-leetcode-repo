/**
Time: O(1)
Memory: O(N * S) where N = total number of queries, S = avg length of each message
**/

class Logger {
public:
    unordered_map<string, int>log;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(log.count(message) && timestamp < log[message]){
            return false;
        }
        log[message] = timestamp + 10;
        return true;
    }
};