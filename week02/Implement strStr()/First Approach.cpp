class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(needle == haystack) return 0;
        int start = 0;
        int count = 0;
        string temp = "";
        int turn1 = haystack.length();
        for(int i=0; i<haystack.length(); i++)
        {
            temp += haystack[i]; //temporary string er modde needle er size moton string add kore check korbo match kore kina
            int turn2 = needle.length()-1; //1 komay disi karon already amra first character nia nisi temp string e
            int j = i+1;
            while(j<turn1 and turn2>0) //j<turn1 dia check kore raksi jeno amar main string er baire chole na jay add korte korte
            {
                temp += haystack[j];
                j++;
                turn2--;
            }
            if(temp == needle) return i;
            else temp = "";
        }
        return -1;
    }
};
//Time complexity nia alap korle,,,amra dekhi je worst case e eta O(n^2) time khete pare,,karon holo,,constraint e bola ase je needle er length
//hote pare main string er shoman !!! so eita khub ekta valo approach hote pare na! 
//Amader uchit O(n) er vetor solve korar try kora 


