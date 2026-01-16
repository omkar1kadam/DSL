public class Trie {
    private TrieNode root;
    
    public Trie(){
        root = new TrieNode();
    }
    
    public void insert(String word){
        TrieNode node = root;
        
        for (char ch:word.toCharArray()){
            int idx = ch - 'a';
            
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            
            node = node.children[idx];
        }
        
        node.isEnd = true;
    }
    
    public boolean search(String word){
        TrieNode node = root;
        
        for (char ch: word.toCharArray()){
            int idx = ch - 'a';
            
            if (node.children[idx] == null) {
                return false;
            }
            
            node = node.children[idx];
        }
        
        return node.isEnd;
    }
    
    public boolean startsWith(String word){
        TrieNode node = root;
        
        for(char ch: word.toCharArray()){
            int idx = ch - 'a';
            
            if (node.children[idx] == null){
                return false;
            }
            
            node = node.children[idx];
        }
        return true;
    }
    
    public void display(){
        System.out.println("Words in trie are:");
        displayHelper(root, new StringBuilder());
    }
    
    private void displayHelper(TrieNode node, StringBuilder sb) {
        if (node.isEnd){
            System.out.println(sb.toString());
        }
        for (int i=0; i<26; i++){
            if (node.children[i] != null) {
                sb.append((char) (i + 'a'));
                displayHelper(node.children[i],sb);
                sb.deleteCharAt(sb.length() -1);
            }
        }
    }
    
    public static void main(String[] args){
        Trie trie = new Trie();
        
        trie.insert("apple");
        trie.insert("app");
        
        System.out.println(trie.search("apple"));
        System.out.println(trie.search("app"));
        System.out.println(trie.search("appl"));
        System.out.println(trie.startsWith("ap"));
        System.out.println(trie.startsWith("bat"));
        
        trie.display();
    }
}

class TrieNode {
    TrieNode[] children;
    boolean isEnd;
    
    public TrieNode(){
        children = new TrieNode[26];
        isEnd = false;
    }
}
