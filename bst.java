public class BinarySearchTree {
    
    Node root;
    
    public void insert(int data){
        root = insertUsingRecursion(root,data);
    }
    
    private Node insertUsingRecursion(Node root,int data){
        if (root == null){
            return new Node(data);
        }
        if (data < root.data){
            root.left = insertUsingRecursion(root.left,data);
        } else if (data > root.data) {
            root.right = insertUsingRecursion(root.right,data);
        }
        return root;
    }
    
    public boolean search(int data){
        return search(root,data);
    }
    
    private boolean search(Node root,int data){
        if (root == null){
            return false;
        }
        
        if (root.data == data){
            return true;
        }
        
        if (data < root.data){
            return search(root.left,data);
        } else {
            return search(root.right,data);
        }
    }
    
    public void delete(int data){
        root = delete(root,data);
    }
    
    private Node delete(Node root,int data){
        if (root == null){
            return null; // node is not found
        }
        
        if (data < root.data){
            root.left = delete(root.left,data);
        } else if (data > root.data){
            root.right = delete(root.right,data);
        } else {
            // node is found
            
            if (root.left == null && root.right == null){
                return null;
            }
            
            if (root.left == null){
                return root.right;
            }
            if (root.right == null){
                return root.left;
            }
            
            int successor = findMinValue(root.right);
            root.data = successor;
            root.right = delete(root.right,successor);
        }
        return root;
    }
    
    private int findMinValue(Node root){
        while (root.left != null){
            root = root.left;
        }
        return root.data;
    }
    
    public void update(int olddata,int newdata){
        if (!search(olddata)){
            System.out.println("value not found!");
            return;
        }
        
        if (search(newdata)){
            System.out.println("data already exits");
            return;
        }
        
        delete(olddata);
        insert(newdata);
    }
    
    public void display(){
        inorder(root);
        System.out.println("");
        preorder(root);
        System.out.println("");
        postorder(root);
        System.out.println("");
    }
    
    private void inorder(Node root){
        if (root == null){
            return;
        }
        
        inorder(root.left);
        System.out.print(root.data+" ");
        inorder(root.right);
    }
    
    private void preorder(Node root){
        if (root == null){
            return;
        }
        
        System.out.print(root.data+" ");
        preorder(root.left);
        preorder(root.right);
    }
    
    private void postorder(Node root){
        if (root == null){
            return;
        }
        
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data+" ");
    }
    
    
    public static void main(String[] args){
        
        BinarySearchTree bst = new BinarySearchTree();
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(2);
        bst.insert(7);
        
        bst.display();
        
        System.out.println("Search 7: " + bst.search(7));   // true
        System.out.println("Search 14: " + bst.search(14)); 
        
        bst.delete(2);
        bst.display();
        
        System.out.println("updating");
        bst.update(5,2);
        bst.display();
    }
}


































class Node {
    int data;
    Node left;
    Node right;
    
    Node(int data){
        this.data = data;
        left = null;
        right = null;
    }
}
