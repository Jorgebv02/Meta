/*
	Valgol Parser

	Grammar:

	Expr   -> Term Expr'
	Expr'  -> '+' Term | epsilon
	Term   -> Factor Term’
	Term'  -> '*' Expr | epsilon
	Factor -> .id | '( Expr ')'
*/

#include "shunting-yard.hpp"

using namespace std;
using namespace Dijkstra;

// expression tree node 
struct et 
{ 
	char value; 
	et* left, *right; 
};

// utility function to check if 'c' is an operator 
bool is_operator(char c) 
{ 
	if (c == '+' || c == '*') return true; 
	return false; 
} 

void post_order(et *t, int indent=0)
{
    if (t != NULL) {
        if (t->left) post_order(t->left, indent + 4);
        if (indent) {
            cout << setw(indent) << " ";
        }
        cout << t->value << "\n "; 
        if (t->right) post_order(t->right, indent + 4);
    }
}

// utility function to create a new node 
et* new_node(int v) 
{ 
	et *temp = new et; 
	temp->left = temp->right = NULL; 
	temp->value = v; 
	return temp; 
}

// returns root of constructed tree for given postfix expression 
et* create_tree(string postfix) 
{ 
	stack<et *> st; 
	et *t, *t1, *t2; 
	// traverse through every character of input expression 
	for (int i = 0; i < postfix.length(); i++) { 
		// if operand, simply push into stack 
		if (!is_operator(postfix[i])) { 
			t = new_node(postfix[i]); 
			st.push(t); 
		}
		// operator
		else { 
			t = new_node(postfix[i]);
			// pop two top nodes 
			t1 = st.top(); // store top 
			st.pop();	  //  remove top 
			t2 = st.top(); 
			st.pop(); 
			// make them children 
			t->right = t1; 
			t->left = t2; 
			// add this subexpression to stack 
			st.push(t); 
		} 
	} 
	// only element will be root of expression 
	// tree 
	t = st.top(); 
	st.pop();
	return t; 
} 

int main() 
{
	cout << "Please enter an expression (example: x+y*(z+w)): ";
	string infix;
	cin >> infix;
	auto sy = SY();
	string postfix = sy.infix_to_postfix(infix); 
	et* r = create_tree(postfix); 
	printf("Parser result: \n"); 
	post_order(r); 
	return 0; 
} 
