// TC = O(N)
// MC = O(1)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman{{'I',1}, {'V',5}, {'X',10}, {'L',50},
                                     {'C',100}, {'D',500}, {'M',1000}};

        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            if(roman[s[i+1]] > roman[s[i]] && i+1<s.size()){
                sum += roman[s[i+1]] - roman[s[i]];
                i++;
            }
            else{
                sum += roman[s[i]];
            }
        }
        return sum;
    }
};
/***************************************************/
// TC = O(N)
// MC = O(1)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='I' && s[i+1]=='V'){
                sum += 4;i++;
            }
            else if(s[i]=='I' && s[i+1]=='X'){
                sum += 9; i++;
            }
            else if(s[i]=='X' && s[i+1]=='L'){
                sum += 40;i++;
            }
            else if(s[i]=='X' && s[i+1]=='C'){
                sum += 90;i++;
            }
            else if(s[i]=='C' && s[i+1]=='D'){
                sum += 400;i++;
            }
            else if(s[i]=='C' && s[i+1]=='M'){
                sum += 900;i++;
            }
            else{
                sum += roman[s[i]];
            }
        }
        return sum;
    }
};
