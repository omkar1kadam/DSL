

public class BinarySearchTree {
    Node root;
    
    BinarySearchTree(){
        root = null;
    }
    
    
    public void insert(int data){
        root = insertRec(root,data);
    }
    
    private Node insertRec(Node root, int data){
        if (root == null){
            return new Node(data);
        }
        
        if (data < root.data) {
            root.left = insertRec(root.left,data);
        } else if (data > root.data) {
            root.right = insertRec(root.right,data);
        }
        
        return root;
    }
    
    public void display(){
        inorder(root);
        System.out.println();
    }
    
    public void inorder(Node root){
        if (root == null){
            return;
        }
        
        
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }
    
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        bst.insert(10);
        bst.insert(7);
        bst.insert(3);
        bst.insert(8);
        
        bst.display();
    }
}


class Node {
    int data;
    Node left;
    Node right;

    Node(int d){
        data = d;
        left = null;
        right = null;
    }
}





