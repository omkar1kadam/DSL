class Main {
    public static void main(String[] args) {
        ExpressionTree et = new ExpressionTree();
        String prefix = "+--a*bc/def";

        et.buildFromPrefix(prefix);

        System.out.print("Inorder (Non-Recursive): ");
        et.inorderNonRecursive();
        System.out.println();

        System.out.print("Postorder (Non-Recursive): ");
        et.postorderNonRecursive();
        System.out.println();
    }
}
class Node{
    char data;
    Node left;
    Node right;
    
    Node(char d){
        data = d;
        left = null;
        right = null;
    }
}
class NodeStack{
    Node[] stck = new Node[100];
    int top = -1;
    void push(Node data){
        if (!isFull()){
            stck[++top] = data;
        } else {
            System.out.println("push func! stack is full");
        }
    }
    Node pop(){
        if (!isEmpty()){
            return stck[top--];
        }
        return null;
    }
    boolean isFull(){
        return (top == stck.length - 1);
    }
    boolean isEmpty(){
        return (top == -1);
    }
    void display(){
        for (int i=0; i<stck.length; i++){
            System.out.println(stck[i]);
        }
    }
}

class ExpressionTree{
    Node root;
    
    void buildFromPrefix(String prefix){
        NodeStack st = new NodeStack();
    
        for (int i = prefix.length()-1; i>= 0; i--){
            char ch = prefix.charAt(i);
            
            //operand
            if (Character.isLetterOrDigit(ch)){
                st.push(new Node(ch));
            }
            //operator
            else {
                Node left = st.pop();
                Node right = st.pop();
                
                Node node = new Node(ch);
                node.left = left;
                node.right = right;
                
                st.push(node);
            }
        }
        root = st.pop();
    }
    
    void inorderNonRecursive(){
        NodeStack st = new NodeStack();
        Node curr = root;
        
        while(curr != null || !st.isEmpty()){
            while(curr != null){
                st.push(curr);
                curr = curr.left;
            }
            
            curr = st.pop();
            System.out.print(curr.data + " ");
            curr = curr.right;
        }
    }
    
    void postorderNonRecursive(){
        if (root == null) return;
        
        NodeStack s1 = new NodeStack();
        NodeStack s2 = new NodeStack();
        
        s1.push(root);
        
        while(!s1.isEmpty()){
            Node temp = s1.pop();
            s2.push(temp);
            
            if(temp.left != null){
                s1.push(temp.left);
            }
            if(temp.right != null){
                s1.push(temp.right);
            }
        }
        while(!s2.isEmpty()){
            System.out.print(s2.pop().data + " ");
        }
    }
}
