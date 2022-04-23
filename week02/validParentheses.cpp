Problem Link: https://leetcode.com/problems/valid-parentheses/

TC: (n);
sc: (n);

bool isValid(string s) {
    stack<char> openingBrks;
    
    map<char,char> symbols;
    symbols[')']='(';
    symbols['}']='{';
    symbols[']']='[';
    
    
    for(int i=0 ; i<s.size() ; i++){
        
        if(s[i]==')' || s[i]=='}' || s[i]==']'){
            
            if(openingBrks.size()>0 && openingBrks.top()==symbols[s[i]]){
                openingBrks.pop();
            }else{
                return false;
            }
            
        }else{
            openingBrks.push(s[i]);
        }
        
    }
    
    if(openingBrks.size()==0){
        return true;
    }
    return false;
    
}
