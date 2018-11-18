//
//  tokenizer.cpp
//  Problem #1: Valgol Tokenizer
//
//  Scanner For Valgol Code
//
// Compile with:
//     reflex tokenizer.l
//     Mac: c++ -Ireflex/include -o tokenizer lex.yy.cpp /Users/adrian/Downloads/reflex/lib/libreflex.a
//     Linux: clang++ -Ireflex/include -o tokenizer lex.yy.cpp /home/adrian/Documentos/reflex-1.0.9/reflex/lib/libreflex.a
//     ./tokenizer example.val
//

%top{
	#include <cstdio>
	#include <iostream>
	#include <iomanip>
	#include <fstream>
	using namespace std;
%}

%class{
	ofstream tokens;
	public:
		void close_tokens() {
			tokens.close();
		}
%}

%init{
	tokens.open("tokens.txt", ofstream::out | ofstream::trunc);
%}

%option unicode

DIGIT [0-9]
ID [a-zA-Z_][a-zA-Z0-9_]*
STRING \".*?\"|'.*?'	

%%

({DIGIT}+([.]{DIGIT}*)?|[.]{DIGIT}+) {
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "A real: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

if|until|do|begin|end|var|halt|space|block|function|return  {
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "A keyword: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

load|loadl|store|add|sub|mult|equal|jmp|jmpz|jmpnz {
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "An instruction: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

{ID} {
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "An identifier: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

{STRING} {
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "A string: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

","|";"|":" {
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "A punctuation mark: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

"("|")"|"["|"]"|"{"|"}" {
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "A delimiter: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

"+"|"-"|"*"|"!"|"->"|"=="|"&&"|"||" {
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "An operator: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

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
	lexer.close_tokens();
	if (fd != stdin)
		fclose(fd);
	return 0;
}
