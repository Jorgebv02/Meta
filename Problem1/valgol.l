/* scanner for valgol language */
/*	compile with:
	reflex valgol.l
	c++ -Ireflex/include -o tokenizer lex.yy.cpp /Users/adrian/Downloads/reflex/lib/libreflex.a 
 */

%top{
	#include <cstdio>
	#include <iostream>
	#include <iomanip>
	using namespace std;
%}

%option unicode

DIGIT [0-9]
ID [a-zA-Z_][a-zA-Z0-9_]*
STRING \".*?\"|'.*?'	

%%

({DIGIT}+([.]{DIGIT}*)?|[.]{DIGIT}+) {
	out() << "A real: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

if|until|do|begin|end|var|halt|space|block|function|return  {
	out() << "A keyword: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

load|loadl|store|add|sub|mult|equal|jmp|jmpz|jmpnz {
	out() << "An instruction: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

{ID} out() << "An identifier: " << text() << " at line " << lineno() << " at column " << columno() << endl;

{STRING} out() << "A string: " << text() << " at line " << lineno() << " at column " << columno() << endl;

","|";"|":" out() << "A punctuation mark: " << text() << " at line " << lineno() << " at column " << columno() << endl;

"("|")"|"["|"]"|"{"|"}" out() << "A delimiter: " << text() << " at line " << lineno() << " at column " << columno() << endl;

"+"|"-"|"*"|"!"|"->"|"=="|"&&"|"||" out() << "An operator: " << text() << " at line " << lineno() << " at column " << columno() << endl;

"/*"(.|\n)*?"*/" /* eat up multi-line comments */

[ \t\r\n]+ /* eat up whitespace */

. out() << "Unrecognized character: " << text() << " at line " << lineno() << " at column " << columno() << endl;

%%

int main(int argc, char **argv) {
	FILE *fd = stdin;
	if (argc > 1 && (fd = fopen(argv[1], "r")) == NULL)
		exit(EXIT_FAILURE);
	// create a lexer that consumes a file or reads stdin
	Lexer lexer(fd);
	// here we go!
	lexer.lex();
	if (fd != stdin)
		fclose(fd);
	return 0;
}
