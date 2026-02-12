class Main {
    public static void main(String[] args) {
        BinarySearchTree bt = new BinarySearchTree();
        bt.addWord("omkar","human");
        bt.addWord("apple","fruit");
        bt.addWord("zebra","animal");
        bt.addWord("banana","fruit");
        bt.addWord("abb","idk");
        bt.display();
    }
}
class Node{
    String word;
    String meaning;
    Node left;
    Node right;
    
    Node(String w,String m){
        word = w;
        meaning = m;
    }
}
class BinarySearchTree{
    Node root;
    
    void addWord(String word,String meaning){
        // if the node is null basically the first word
        if (root == null){
            root = new Node(word,meaning);
            return;
        }
        
        Node temp = root;
        
        while(true){
            if(word.compareTo(temp.word) < 0){
                // go left
                if (temp.left == null){
                    temp.left = new Node(word,meaning);
                    break;
                }
                temp = temp.left;
            } else if (word.compareTo(temp.word) > 0){
                // go right
                if(temp.right == null){
                    temp.right = new Node(word,meaning);
                    break;
                }
                temp = temp.right;
            } else {
                // updation logic remains same here too 
                temp.meaning = meaning;
                break;
            }
            
        }
    }
    void deleteWord(){
        
    }
    void display(){
        displayInOrder(root);
    }
    void displayInOrder(Node root){
        if(root == null){
            return;
        }
        
        displayInOrder(root.left);
        System.out.println("Word: "+root.word);
        System.out.println("Meaning: "+root.meaning);
        displayInOrder(root.right);
    }
}











