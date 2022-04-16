// TC: O(N)
// MC: O(1)

class Solution {
    public boolean isAnagram(String s, String t) {
        
        if(s.length() != t.length()) return false;
        
        int[] counter = new int[26];
        for(int i = 0; i<t.length(); ++i) {
            counter[s.charAt(i)-'a']++;
            counter[t.charAt(i)-'a']--;
        }
        
        for(int c: counter) {
            if(c != 0) return false;
        }
        return true;
    }
}