#include "parserVagol.h"

parserVagol::parserVagol()
{
    //ctor
}

//  function to check if a given token is an operator
bool parserVagol::is_operator(char token)
{
	if (token == '+' || token == '*') return true;
	return false;
}
// This function is used to create a new node
node* parserVagol::new_node(int v)
{
	node *temporalNode = new node;
	temporalNode->left = temporalNode->right = NULL;
	temporalNode->value = v;
	return temporalNode;
}

// This function returns root of constructed tree for given postfix expression
node* parserVagol::result(string postfixExpr)
{
	stack<node *> stackT;
	node *tmp, *tmp1, *tmp2;
	int i = 0;
	// traverse through every character of input expression
	while(i < postfixExpr.length()) {
		// if operand, simply push into stack
		if (!is_operator(postfixExpr[i])) {
			tmp = new_node(postfixExpr[i]);
			stackT.push(tmp);
		}
		// operator
		else {
			tmp = new_node(postfixExpr[i]);
			// pop two top nodes
			tmp1 = stackT.top(); // store top
			stackT.pop();	  //  remove top
			tmp2 = stackT.top();
			stackT.pop();
			// make them children
			tmp->right = tmp1;
			tmp->left = tmp2;
			// add this subexpression to stack
			stackT.push(tmp);
		}
		i++;
	}
	// only element will be root of expression
	// tree
	tmp = stackT.top();
	stackT.pop();
	return tmp;
}
/*Show the post order form of an expression*/
void parserVagol::post_order(node *t, int i)
{
    if (t != NULL) {
        if (t->left) post_order(t->left, i + 4);
        if (i) {
            cout << setw(i) << " ";
        }
        cout << t->value << "\n ";
        if (t->right) post_order(t->right, i + 4);
    }
}

parserVagol::~parserVagol()
{
    //dtor
}
