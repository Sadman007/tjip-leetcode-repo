//13. Roman to Integer
//Tc- 0(n)
//sc -0(1)
class Solution
{
public:
    int getValue(char ch)
    {
        if (ch == 'I') return 1;
        else if (ch  == 'V') return 5;
        else if (ch == 'X') return 10;
        else if (ch == 'L') return 50;
        else if (ch == 'C') return 100;
        else if (ch == 'D') return 500;
        else if (ch == 'M') return 1000;
        else return 0;
    }
    int romanToInt(string s)
    {
        int ans = 0;
        for(int i = 0; i < s.size() ; i++)
        {
            int firstVal = 0;
            int secVal = 0;
            firstVal = getValue(s[i]);
            secVal = getValue(s[i+1]);
            if(i < s.size()-1 && firstVal < secVal)
            {
                ans += secVal - firstVal;
                i++;
            }
            else
            {

                ans += firstVal;
            }
        }
        return ans;
    }
};

//using unordered map
//Tc- 0(n)
//sc -0(1)
/*
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char,int> romanNum = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans = 0, i = 0;
        while(i < s.size() -1)
        {
            int firstval = romanNum[s[i]];
            int secval = romanNum[s[i+1]];
            if(firstval < secval)
            {
                ans += secval - firstval;
                i +=2;
            }
            else
            {
                ans += firstval;
                i++;
            }
        }

        if( i != s.size())
        {
            ans += romanNum[s[i]];
        }
        return ans;
    }
};
*/
