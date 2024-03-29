/* 
    Dijkstra's Shunting-Yard Algorithm
    C++ library to convert infix expression to postfix
*/

#include <bits/stdc++.h> 

namespace Dijkstra {

    class SY {

        private:
            int prec(char c)
            { 
                if (c == '*') return 2; 
                else if(c == '+') return 1; 
                else return -1; 
            }

        public:
            std::string infix_to_postfix(std::string s) 
            { 
                std::stack<char> st; 
                st.push('N'); 
                int l = s.length(); 
                std::string ns; 
                for (int i = 0; i < l; i++) { 
                    // if the scanned character is an operand, add it to output string. 
                    if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
                    ns+=s[i]; 
                    // if the scanned character is an ‘(‘, push it to the stack. 
                    else if(s[i] == '(') 
                    st.push('(');
                    // if the scanned character is an ‘)’, pop and to output string from the stack 
                    // until an ‘(‘ is encountered. 
                    else if (s[i] == ')') { 
                        while(st.top() != 'N' && st.top() != '(') { 
                            char c = st.top(); 
                            st.pop(); 
                            ns += c; 
                        } 
                        if (st.top() == '(') { 
                            char c = st.top(); 
                            st.pop(); 
                        } 
                    } 
                    // if an operator is scanned 
                    else { 
                        while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) { 
                            char c = st.top(); 
                            st.pop(); 
                            ns += c; 
                        } 
                        st.push(s[i]); 
                    } 
            
                } 
                // pop all the remaining elements from the stack
                while (st.top() != 'N') { 
                    char c = st.top(); 
                    st.pop(); 
                    ns += c; 
                }
                return ns;
            }
    };
}
