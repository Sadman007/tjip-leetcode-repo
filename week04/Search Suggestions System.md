class TrieNode {
    String word;
    TrieNode[] childNode;
    
    TrieNode() {
        word = "";
        childNode = new TrieNode[26];
    }
}

class Solution {
    public TrieNode root;
    
    Solution() {
        this.root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode currentNode = root;
        
        for(int i = 0; i < word.length(); ++i) {
            int position = word.charAt(i) - 'a';
            
            if(currentNode.childNode[position] ==  null) {
                currentNode.childNode[position] = new TrieNode();
            }
        }
        currentNode.word = word;
    }
    
     List<String> dfs(TrieNode current, List<String> words) {
         
        System.out.println(current);
         if(current != null) System.out.println(current.word);
        
        if(current == null || words.size() == 3) return words;
         
         // System.out.println(current.word);
        
        if( words.size() < 3) {
            System.out.println(current.word);
            words.add(current.word);
        }
        
        for(int i  = 0 ; i < 26; ++i) {
            System.out.println("catch");
            words = dfs(current.childNode[i], words);
        }
        
        return words;
    }
    
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        for(int i = 0; i < products.length; ++i) {
            insert(products[i]);
        }
        List<List<String>> resultList =  new ArrayList();
        char [] searchWordChar = searchWord.toCharArray();
        
        for(char c : searchWordChar) {
            // System.out.println(c);
            if(root != null && root.childNode[c - 'a'] != null) {
                 root = root.childNode[c - 'a'];
                 List<String> words = new ArrayList();
                 dfs(root, words);
                 resultList.add(words);
            }else {
                root = null;
            }
        }
         return resultList;
    }
}