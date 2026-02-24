class Main {
    public static void main(String[] args) {
        System.out.println("Try programiz.pro");
        BinaryTree bt = new BinaryTree();
        bt.addNode(10);
        bt.addNode(5);
        bt.addNode(15);
        bt.addNode(3);
        bt.addNode(7);
        bt.addNode(12);
        bt.addNode(18);
        bt.addNode(1);
        bt.addNode(4);
        bt.addNode(6);
        bt.addNode(8);
        bt.addNode(11);
        bt.addNode(13);
        bt.addNode(17);
        bt.addNode(20);
        //bt.delete(15);
        //bt.display();
        System.out.println("bfs: ");
        bt.bfs();
        System.out.println("dfs: ");
        bt.dfs();
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
        preOrder(root.left);
        preOrder(root.right);
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
        
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data+" ");
    }
    void bfs(){
        if (root == null){
            return;
        }
        Queue q = new Queue();
        q.enqueue(root);
        
        while(!q.isEmpty()){
            Node current = q.dequeue();
            System.out.print(current.data+" ");
            if(current.left != null){
                q.enqueue(current.left);
            }
            if(current.right != null){
                q.enqueue(current.right);
            }
        }
    }
    void dfs(){
        
    }
}
class Queue {
    Node[] data = new Node[100];
    int front;
    int rear;
    Queue(){
        front = -1;
        rear = -1;
    }
    void enqueue(Node value){
        if (front == -1){
            front ++;
        }
        if (!isFull()){
            data[++rear] = value;
        }else{
            System.out.println("Queue is full");
        }
    }
    Node dequeue(){
        Node val;
        if(!isEmpty()){
            val = data[front];
            if (front == rear){
                front = rear = -1;
            }
            else front++;
            return val;
        }
        return null;
    }
    boolean isEmpty(){
		return rear == -1; 
	}
	boolean isFull(){
		return rear == 100-1;
	}
}
class Stack{
    Node[] data = new Node[100];
    int top;
    Stack(){
        top = -1;
    }
    void push(Node value){
        if(top == -1){
            top++;
        }
        if(!isFull()){
            data[top] = value;
        } else {
            System.out.println("stack is full");
        }
    }
    Node pop(){
        if(isEmpty()){
            System.out.println("stack is empty");
            return null;
            }
        return data[--top];
    }
    boolean isFull(){
        return top >= 100;
    }
    boolean isEmpty(){
        return top == -1;
    }
}



