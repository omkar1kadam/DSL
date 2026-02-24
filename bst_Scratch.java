class Main {
    public static void main(String[] args) {
        System.out.println("Try programiz.pro");
        BinaryTree bt = new BinaryTree();
        bt.addNode(10);
        bt.addNode(5);
        bt.addNode(15);
        bt.display();
        bt.search(15);
        bt.delete(15);
        bt.display();
    }
}
class Node{
    int data;
    Node left;
    Node right;
    Node(int d){
        data =d;
        left = right = null;
    }
}
class BinaryTree{
    Node root;
    
    void addNode(int data){
        if (root == null){
            root = new Node(data);
            return;
        }
        
        Node curr = root;
        while(true){
            if (data<curr.data){
                if(curr.left == null){
                    curr.left = new Node(data);
                    return;
                }
                curr = curr.left;
            } else if (data>curr.data){
                if(curr.right == null){
                    curr.right = new Node(data);
                    return;
                }
                curr = curr.right;
            }
        }
    }
    void search(int data){
        Node curr = root;
        while(true){
            if(data<curr.data){
                if(curr.left == null){
                    System.out.println("Not found");
                }
                curr = curr.left;
            } else if (data > curr.data){
                if(curr.right == null){
                    System.out.println("Not found");
                }
                curr = curr.right;
            }
            
            if(data == curr.data) {
                System.out.println("found");
                return;
            }
        }
    }
    void delete(int data){
        root = deleteRec(root,data);
    }
    Node deleteRec(Node root,int data){
        if(root == null){
            return null;
        }
        if (data < root.data){
            root.left = deleteRec(root.left,data);
        } else if (data > root.data){
            root.right = deleteRec(root.right,data);
        } else{
            if (root.left == null && root.right == null){
                return null;
            }
            if(root.left == null){
                return root.right;
            }
            if(root.right == null){
                return root.left;
            }
            Node successor = findMin(root.right);
            root.data = successor.data;
            root.right = deleteRec(root.right,successor.data);
            
        }
        return root;
    }
    Node findMin(Node root){
        while(root.left != null){
            root = root.left;
        }
        return root;
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

}













