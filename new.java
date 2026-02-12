class Main {
    public static void main(String[] args) {
        // System.out.println("Try programiz.pro");
        
        ExpressionTree et = new ExpressionTree();
        String prefix = "+--a*bc/def";
        
        et.buildFromPrefix(prefix);
        
        System.out.println("Pre Order NonRecursive Traversal");
        et.preOrderNonRecursiveTraversal();
        System.out.println(" ");
        
        System.out.println("in Order NonRecursive Traversal");
        et.inOrderNonRecursiveTraversal();
        System.out.println(" ");
        
        System.out.println("Post Order NonRecursive Traversal");
        et.postOrderNonRecursiveTraversal();
        System.out.println(" ");
    }
}
class Node{
    char data;
    Node left;
    Node right;
    
    Node(char d){
        data = d;
        left = right = null;
    }
}
class NodeStack{
    Node[] stack = new Node[100];
    int top = -1;
    
    void push(Node data){
        if(!isFull()){
            stack[++top] = data;
        }else{
            System.out.println("stack full error");
        }
    }
    Node pop(){
        if(!isEmpty()){
            return stack[top--];
        }else{
            System.out.println("stack empty error");
        }
        return null;
    }
    boolean isFull(){
        return top == stack.length -1;
    }
    boolean isEmpty(){
        return top == -1;
    }
    
}
class ExpressionTree{
    Node root;
    
    void buildFromPrefix(String prefix){
        NodeStack st = new NodeStack();
        
        for(int i=prefix.length()-1; i>=0; i--){
            char ch = prefix.charAt(i);
            
            //operand
            if(Character.isLetterOrDigit(ch)){
                st.push(new Node(ch));
            }
            //operator
            else{
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
    void preOrderNonRecursiveTraversal(){
        if(root == null) return;
        NodeStack st = new NodeStack();
        st.push(root);
        
        while(!st.isEmpty()){
            Node temp = st.pop();
            System.out.print(temp.data+" ");
            
            if(temp.right != null){
                st.push(temp.right);
            }
            if(temp.left != null){
                st.push(temp.left);
            }
        }
    }
    void inOrderNonRecursiveTraversal(){
        NodeStack st = new NodeStack();
        Node curr = root;
        
        while(curr != null || !st.isEmpty()){
            while(curr != null){
                st.push(curr);
                curr = curr.left;
            }
            
            curr = st.pop();
            System.out.print(curr.data+" ");
            curr = curr.right;
        }
    }
    void postOrderNonRecursiveTraversal(){
        if(root == null) return;
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
            System.out.print(s2.pop().data+" ");
        }
    }
    
}
