#include<iostream>
#define MAX 5
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
//implementatio
class ExpressioParsing{};

int main(){
  stack obj;
  obj.push('A');
  obj.push('B');
  obj.push('C');
  obj.push('D');
  obj.push('E');
  obj.push('F');
  cout<<"\nElements Before pop function\n";
  obj.printStack();
  obj.pop();
  obj.pop();
  obj.pop();
  obj.pop();

 cout<<"\nElements After pop function\n";
  obj.printStack();
  return 0;
}
