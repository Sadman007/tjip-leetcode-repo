class TrieNode {
    public boolean isWord;
    public TrieNode[] childNode;

    public TrieNode() {
        this.isWord = false;
        this.childNode = new TrieNode[26];
    }
}

public class Trie {
    private  TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode currentNode = root;

        for (int i = 0; i<word.length(); ++i) {
            int order = word.charAt(i) - 'a';
            if(currentNode.childNode[order] == null){
                currentNode.childNode[order] = new TrieNode();
            }
            currentNode = currentNode.childNode[order];
        }
        currentNode.isWord = true;
    }


    public boolean search(String word) {
        return search(word, false);
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

    public boolean startsWith(String prefix) {
        return this.search(prefix, true);
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */