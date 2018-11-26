#ifndef PARSERVAGOL_H
#define PARSERVAGOL_H


/*
	Valgol Parser


    The following is the Grammar of this parser:

	Expr   -> Term Expr'
	Expr'  -> '+' Term | epsilon
	Term   -> Factor Term’
	Term'  -> '*' Expr | epsilon
	Factor -> .id | '( Expr ')'
*/

#include "Dijkstra.hpp"

using namespace std;
using namespace Dijkstra;
// expression tree node
struct node
{
    node* left, *right;
	char value;
};

class parserVagol
{
    public:
        parserVagol();
        bool is_operator(char token);
        node* new_node(int v);
        node* result(string postfixExpr);
        void post_order(node *t, int i=0);
        virtual ~parserVagol();

    protected:

    private:
};

#endif // PARSERVAGOL_H

