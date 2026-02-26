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
        System.out.println(" ");
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
    
        while(curr != null){
            if(data < curr.data){
                curr = curr.left;
            } 
            else if(data > curr.data){
                curr = curr.right;
            } 
            else {
                System.out.println("Found");
                return;
            }
        }

    System.out.println("Not found");
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
        //preOrderNonRecursion();
        //inOrderNonRecursion();
        postOrderNonRecursion();
    }
    void preOrderNonRecursion(){
        if(root == null){
            return;
        }
        Stack st = new Stack();
        st.push(root);
        
        while(!st.isEmpty()){
            Node current = st.pop();
            System.out.print(current.data+" ");
            
            if(current.right != null){
                st.push(current.right);
            }
            if(current.left != null){
                st.push(current.left);
            }
        }
    }
    void inOrderNonRecursion(){
        Stack st = new Stack();
        Node current = root;
        
        while(current != null || !st.isEmpty()) {
            while(current != null){
                st.push(current);
                current = current.left;
            }
            current = st.pop();
            System.out.print(current.data+" ");
            
            current = current.right;
        }
    }
    void postOrderNonRecursion(){
        if(root == null){
            return;
        }
        Stack st1 = new Stack();
        Stack st2 = new Stack();
        
        st1.push(root);
        
        while(!st1.isEmpty()){
            Node current = st1.pop();
            st2.push(current);
            
            if(current.left != null){
                st1.push(current.left);
            }
            if(current.right != null){
                st1.push(current.right);
            }
        }
        while(!st2.isEmpty()){
            System.out.print(st2.pop().data+" ");
        }
    }
    // void postOrderNonRecusionUsingOneStack(){
    //     Stack st = new Stack();
    //     Node current = root;
    //     Node lastVisited = null;
        
    //     while(current != null || st.isEmpty()){
            
    //     }
    // }
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
        if(!isFull()){
            data[++top] = value;
        } else {
            System.out.println("stack is full");
        }
    }
    Node peek(){
        if(isEmpty()){
            return null;
        }
        return data[top];
    }
    Node pop(){
        if(isEmpty()){
            System.out.println("stack is empty");
            return null;
            }
        return data[top--];
    }
    boolean isFull(){
        return top == 100-1;
    }
    boolean isEmpty(){
        return top == -1;
    }
}
































