class Main {
    public static void main(String[] args) {
        Stack obj = new Stack();
        // obj.push('1');
        // obj.push('a');
        // obj.display();
        // System.out.println("Try programiz.pro");
        // obj.pop();
        // obj.push('*');
        // obj.display();
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
    Node[] stck = new Node[10];
    int top = -1;
    void push(char data){
        if (!isFull()){
            stck[++top] = data;
        } else {
            System.out.println("push func! stack is full");
        }
    }
    int pop(){
        if (!isEmpty()){
            return stck[top--];
        } else {
            System.out.println("pop func! stack is empty");
            return '\0';
        }
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
    
    void builFromPrefix(String prefix){
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
            
        }
        
    }
}







