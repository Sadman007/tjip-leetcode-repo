class TrieNode {
    boolean isWord;
    TrieNode[] childNode;
    
    TrieNode() {
        isWord = false;
        childNode = new TrieNode[26];
    }
}
class Solution {
    private TrieNode root;
    
    Solution() {
        this.root = new TrieNode();
    }
    
    public void insert(String s) {
        TrieNode currentNode = root;
        
        for(int i = 0; i < s.length(); ++i) {
            int position = s.charAt(i) - 'a';
            
            if(currentNode.childNode[position] == null) {
                currentNode.childNode[position] = new TrieNode();
            }
            
            currentNode =  currentNode.childNode[position];
        }
        currentNode.isWord = true;
    }
    
     private boolean search(String word, boolean isPrefixSearch) {
        TrieNode currentNode = root;

        for(int i = 0; i <word.length(); ++i) {
            int order = word.charAt(i) - 'a';
            if(currentNode.childNode[order] == null) {
                return false;
            }
            currentNode = currentNode.childNode[order];
        } 
         return (currentNode != null) && (currentNode.isWord | isPrefixSearch);
        // return (currentNode.childNode == null | isPrefixSearch) ? false : true;
    }
    
    public boolean wordBreak(String s, List<String> wordDict) {
        for(int i = 0; i < wordDict.size(); ++i) {
            insert(wordDict.get(i));
        }
        
        boolean [] dp = new boolean [s.length() + 1];
        
        // for(int i = 0; i < dp.length; ++i) {
        //     System.out.println(dp[i]);
        // }
        
        char[] charArray = s.toCharArray();
        dp[0] = true;
        
        for(int i = 0; i < charArray.length; ++i) {
            // System.out.println(charArray[i]);
            if(!dp[i]) continue;
            
            int j = i;
            
            TrieNode currentNode =  root;
            
            while(j < charArray.length && currentNode.childNode[charArray[j] - 'a'] !=  null) {
                currentNode =  currentNode.childNode[charArray[j++] - 'a'];
               if(currentNode.isWord == true) {
                   // System.out.println("Saved");
                   dp[j] = true;
               }
            }
            
        }
        
        //   for(int i = 0; i < dp.length; ++i) {
        //     System.out.println(dp[i]);
        // }
        // System.out.println(dp[s.length()]);
        return dp[s.length()];
    }
    
}




