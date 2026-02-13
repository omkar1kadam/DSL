class Main {
    public static void main(String[] args) {
        BinarySearchTree bt = new BinarySearchTree();
        bt.addNode(10);
        bt.addNode(5);
        bt.addNode(15);
        bt.display();
        bt.searchNode(15);
        bt.deleteNode(15);
        System.out.println("Try programiz.pro");
    }
}
class Node{
    int data;
    Node left;
    Node right;
    
    Node(int d){
        data = d;
        left = right = null;
    }
}
class BinarySearchTree{
    Node root;
    
    void addNode(int data){
        if(root == null){
            root = new Node(data);
            return;
        }
        Node curr = root;
        while(true){
            if(data<curr.data){
                if(curr.left == null){
                    curr.left = new Node(data);
                    break;
                }
                curr = curr.left;
            } else if(data>curr.data){
                if(curr.right == null){
                    curr.right = new Node(data);
                    break;
                }
                curr = curr.right;
            }
        }
    }
    void display(){
        //preOrder(root);
        //System.out.println(" ");
        inOrder(root);
        //System.out.println(" ");
        //postOrder(root);
    }
    void preOrder(Node root){
        if (root == null){
            return;
        }
        System.out.print(root.data+" ");
        inOrder(root.left);
        inOrder(root.right);
    }
    void inOrder(Node root){
        if (root == null){
            return;
        }
        
        inOrder(root.left);
        System.out.print(root.data+" ");
        inOrder(root.right);
    }
    void postOrder(Node root){
        if (root == null){
            return;
        }
        
        inOrder(root.left);
        inOrder(root.right);
        System.out.print(root.data+" ");
    }
    void searchNode(int data){
        Node curr = root;
        while(true){
            if(data<curr.data){
                if(curr.left == null){
                    System.out.println("not found");
                    break;
                }
                curr = curr.left;
            } else if (data > curr.data){
                if(curr.right == null){
                    System.out.println("not found");
                    break;
                }
                curr = curr.right;
            }
            if(data == curr.data){
                System.out.println("Found");
                break;
            }
        }
    }
    void deleteNode(int data){
        if (root == null){
            return;
        }
        
    }
}
