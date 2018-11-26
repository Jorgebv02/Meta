/*
    C++ library to convert infix expression to postfix
*/

#include <bits/stdc++.h>
using namespace std;
namespace Dijkstra{

    class Algorithm {

        private:
            /* Function to check if the token before some expression
             is the operator * or + */
            int predec(char token)
            {
                if (token == '*') return 2;
                else if(token == '+') return 1;
                else return -1;
            }

        public:
            /*This function takes an expression and convert it from
            infix to postfix.
            FOR EXAMPLE:
                 infix: A + B   ----- postfix: A B +
                 infix: (10 + 5 * 10 + 3) * 3 ------- postfix: 10 5 10 * 3 + + 3
            */


            string inf_to_postf(string expression)
            {
                stack<char> stackT;
                stackT.push('N');
                int l = expression.length();   // Store the lenght of the expression
                string newExpression;
                int i = 0;
                while(i < l) {
                    // if the scanned character is an operand, add it to output string.
                    if((expression[i] >= 'a' && expression[i] <= 'z')||(expression[i] >= 'A' && expression[i] <= 'Z'))
                    newExpression+=expression[i];
                    // if the scanned character is an ‘(‘, push it to the stack.
                    else if(expression[i] == '(')
                    stackT.push('(');
                    // if the scanned character is an ‘)’, pop and to output string from the stack
                    // until an ‘(‘ is encountered.
                    else if (expression[i] == ')') {
                        while(stackT.top() != 'N' && stackT.top() != '(') {
                            char c = stackT.top();
                            stackT.pop();
                            newExpression += c;
                        }
                        if (stackT.top() == '(') {
                            char c = stackT.top();
                            stackT.pop();
                        }
                    }
                    // if an operator is scanned
                    else {
                        while(stackT.top() != 'N' && predec(expression[i]) <= predec(stackT.top())) {
                            char c = stackT.top();
                            stackT.pop();
                            newExpression += c;
                        }
                        stackT.push(expression[i]);
                    }
                 i++;
                }
                // pop all the remaining elements from the stack
                while (stackT.top() != 'N') {
                    char c = stackT.top();
                    stackT.pop();
                    newExpression += c;
                }
                return newExpression;   // Returns the new expression in postfix form
            }
    };
}


