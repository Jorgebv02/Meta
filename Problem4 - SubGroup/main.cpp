#include <iostream>
#include "parserVagol.h"

using namespace std;

int main()
{
    parserVagol *pv = new parserVagol();
	cout << "Enter an expression in infix form: ";
	string infixform;
	cin >> infixform;
	auto alg = Dijkstra::Algorithm();
	string postfixform = alg.inf_to_postf(infixform);
	node* r = pv->result(postfixform);
	printf("Result of parser: \n");
	pv->post_order(r);
	return 0;
}
