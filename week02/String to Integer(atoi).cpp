class Solution {
public:
    int myAtoi(string s) {
        int sz= s.size();
        if(sz==0)
            return sz;
        
        // remove leading space
        int i=0;
        while(i<sz && s[i]==' ' )
            i++;
        
        
        if(i==sz)
            return 0;
        int sign= s[i]=='-'?-1:1;
        
        if(s[i]=='-' || s[i]=='+')
            i++;
        long result=0;
        
        while(i<sz && s[i]>='0' && s[i]<='9' )
        {
            result= result*10+ sign*(s[i]-'0');
            
            if(result<INT_MIN)
                return INT_MIN;
            if(result>INT_MAX)
                return INT_MAX;
            i++;
        }
        return result;
    }
};