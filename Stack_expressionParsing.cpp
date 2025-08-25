#include<iostream>
#include<limits>
#define MAX 1000
using namespace std;
class stack
{
   private: char stk[MAX];
              int top;

   public:
             stack(){
             top=-1;
             }

             bool isStackEmpty(){
                if(top==-1)
                    return true;
                else
                    return false;
             }

             bool isStackfull(){
                if(top==MAX-1)
                    return true;
                else
                    return false;
             }

             void push(char val){
                 if(!isStackfull())
                    stk[++top]=val;
                 else
                    cout<<"\nStack is full\n";
             }

             int pop(){
                    if(!isStackEmpty())
                        return stk[top--];
                    else
                      cout<<"\nStack is Empty\n";
                    return '\0';
             }

             void printStack(){
              for(int i=top;i>=0;i--)
                 cout<<stk[i]<<"\n";
             }


};
//implementation Class
class ExpressionParsing{
	private:
		char E[100]; // to save the given mathematical expression
		
	public:
		void readExpression(){
			cout << "Enter any Mathematical expression::";
			cin.getline(E,100);	
		}
		void printExpression(){
			cout << "THe Mathematical expression::";
			cout << E << endl;
		}
		void wellFormExpression(){
			stack obj;
			int i=0;
			char ch;
			bool flagValid = true;
			while(E[i] != '\0') {
				if(E[i] == '(' || E[i] == '{' || E[i] == '[' || E[i] == '<') {
					obj.push(E[i]);
				} else {
					if(E[i] == ')' || E[i] == '}' || E[i] == ']' || E[i] == '>'){
						ch = obj.pop();
						if(E[i] == ')' && ch != '('|| E[i] == '}' && ch != '{' || E[i] == ']' && ch != '[' || E[i] == '>' && ch != '<') {
							flagValid = false;
						}
					}
				}
				i++;
			}
			if(obj.isStackEmpty() && flagValid){
				cout << "The expression is well form expression TRUE" << endl;
			} else {
				cout << "The expression is not well form expression FALSE" << endl;
			}
		}
};

int main(){
	ExpressionParsing exp;
	exp.readExpression();
	exp.printExpression();
	exp.wellFormExpression();
	return 0;
}


  



