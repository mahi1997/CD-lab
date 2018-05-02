#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

// get weight of operators as per precedence

int getWeight(char ch) {
   switch (ch) {
      case '/':
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;
   }
}

// convert infix expression to postfix using a stack
void infixtopostfix(char infix[], char postfix[], int size) {
   stack<char> S;
   int weight;
   int i = 0;
   int k = 0;
   char ch;
   
   while (i < size) {
      ch = infix[i];
      if (ch == '(') {
         // simply push the opening bracket
         S.push(ch);
         i++;
         continue;
      }
      //on closing bracket
      if (ch == ')') {
         
         while (!S.empty() && S.top() != '(') {
            postfix[k++] = S.top();
            S.pop();

         }
         // pop  the opening bracket
         if (!S.empty()) {
            S.pop();
         }
         i++;
         continue;
      }
      weight = getWeight(ch);
      if (weight == 0) {
         //for operand
         postfix[k++] = ch;

      }
      else {
         // we saw an operator
         if (S.empty()) {
            // simply push the operator onto stack if is empty
            
            S.push(ch);
         }
         else {
            
            while (!S.empty() && S.top() != '(' &&
                  weight <= getWeight(S.top())) {
               postfix[k++] = S.top();
               S.pop();

            }
            // push the current operator onto stack
            S.push(ch);
         }
      }
      i++;
   }
   // pop of the remaining operators present in the stack
   
   while (!S.empty()) {
      postfix[k++] = S.top();
      S.pop();
   }
   
}


int main() {
    string in;
    cin>>in;
    int len = in.length();
    char infix[len]; 
    strcpy(infix, in.c_str());
   
   
   char postfix[len];
   infixtopostfix(infix,postfix,len);
   cout<<"\nInfix Expression :: "<<infix;
   cout<<"\nPostfix Expression :: "<<postfix;
   cout<<endl;
   return 0;
}
