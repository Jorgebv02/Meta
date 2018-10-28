// lex.yy.cpp generated by reflex 1.0.9 from valgol.l

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  OPTIONS USED                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#define REFLEX_OPTION_lex                 lex
#define REFLEX_OPTION_lexer               Lexer
#define REFLEX_OPTION_outfile             lex.yy.cpp
#define REFLEX_OPTION_unicode             true

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %top{ user code %}                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 8 "valgol.l"

	#include <cstdio>
	#include <iostream>
	#include <iomanip>
	#include <fstream>
	using namespace std;


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  REGEX MATCHER                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  ABSTRACT LEXER CLASS                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/abslexer.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  LEXER CLASS                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class Lexer : public reflex::AbstractLexer<reflex::Matcher> {
#line 16 "valgol.l"

	ofstream tokens;
	public:
		void close_tokens() {
			tokens.close();
		}

 public:
  typedef reflex::AbstractLexer<reflex::Matcher> AbstractBaseLexer;
  Lexer(
      const reflex::Input& input = reflex::Input(),
      std::ostream&        os    = std::cout)
    :
      AbstractBaseLexer(input, os)
  {
#line 24 "valgol.l"

	tokens.open("tokens.txt", ofstream::out | ofstream::trunc);

  }
  static const int INITIAL = 0;
  virtual int lex();
  int lex(
      const reflex::Input& input,
      std::ostream        *os = NULL)
  {
    in(input);
    if (os)
      out(*os);
    return lex();
  }
};

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %{ user code %}                                                //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 1 "valgol.l"
/* scanner for valgol language */
/*	compile with:
	reflex valgol.l
	c++ -Ireflex/include -o tokenizer lex.yy.cpp /Users/adrian/Downloads/reflex/lib/libreflex.a
	./tokenizer valgol_example.txt
 */


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 2: rules                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

int Lexer::lex()
{
  static const reflex::Pattern PATTERN_INITIAL("(?m)((?:(?:[0-9])+(?:\\x2e(?:[0-9])*)?|\\x2e(?:[0-9])+))|(if|until|do|begin|end|var|halt|space|block|function|return)|(load|loadl|store|add|sub|mult|equal|jmp|jmpz|jmpnz)|((?:(?:[A-Z]|_|[a-z])(?:[0-9]|[A-Z]|_|[a-z])*))|((?:\"(?:.[\\x80-\\xbf]*)*?\"|'(?:.[\\x80-\\xbf]*)*?'))|((?:\\Q,\\E)|(?:\\Q;\\E)|(?:\\Q:\\E))|((?:\\Q(\\E)|(?:\\Q)\\E)|(?:\\Q[\\E)|(?:\\Q]\\E)|(?:\\Q{\\E)|(?:\\Q}\\E))|((?:\\Q+\\E)|(?:\\Q-\\E)|(?:\\Q*\\E)|(?:\\Q!\\E)|(?:\\Q->\\E)|(?:\\Q==\\E)|(?:\\Q&&\\E)|(?:\\Q||\\E))|((?:\\Q/*\\E)(?:(?:.[\\x80-\\xbf]*)|\\n)*?(?:\\Q*/\\E))|((?:[\\x09\\x0a]|\\x0d|\\x20)+)|((?:.[\\x80-\\xbf]*))");
  if (!has_matcher())
  {
    matcher(new Matcher(PATTERN_INITIAL, stdinit(), this));
  }
  while (true)
  {
        switch (matcher().scan())
        {
          case 0:
            if (matcher().at_end())
            {
              return 0;
            }
            else
            {
              out().put(matcher().input());
            }
            break;
          case 1: // rule at line 36: (?:(?:[0-9])+(?:\x2e(?:[0-9])*)?|\x2e(?:[0-9])+)
#line 36 "valgol.l"
{
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "A real: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

            break;
          case 2: // rule at line 41: if|until|do|begin|end|var|halt|space|block|function|return
#line 41 "valgol.l"
{
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "A keyword: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

            break;
          case 3: // rule at line 46: load|loadl|store|add|sub|mult|equal|jmp|jmpz|jmpnz
#line 46 "valgol.l"
{
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "An instruction: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

            break;
          case 4: // rule at line 51: (?:(?:[A-Z]|_|[a-z])(?:[0-9]|[A-Z]|_|[a-z])*)
#line 51 "valgol.l"
{
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "An identifier: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

            break;
          case 5: // rule at line 56: (?:"(?:.[\x80-\xbf]*)*?"|'(?:.[\x80-\xbf]*)*?')
#line 56 "valgol.l"
{
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "A string: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

            break;
          case 6: // rule at line 61: (?:\Q,\E)|(?:\Q;\E)|(?:\Q:\E)
#line 61 "valgol.l"
{
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "A punctuation mark: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

            break;
          case 7: // rule at line 66: (?:\Q(\E)|(?:\Q)\E)|(?:\Q[\E)|(?:\Q]\E)|(?:\Q{\E)|(?:\Q}\E)
#line 66 "valgol.l"
{
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "A delimiter: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

            break;
          case 8: // rule at line 71: (?:\Q+\E)|(?:\Q-\E)|(?:\Q*\E)|(?:\Q!\E)|(?:\Q->\E)|(?:\Q==\E)|(?:\Q&&\E)|(?:\Q||\E)
#line 71 "valgol.l"
{
	tokens << text() << " " << lineno() << " " << columno() << endl;
	out() << "An operator: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

            break;
          case 9: // rule at line 76: (?:\Q/*\E)(?:(?:.[\x80-\xbf]*)|\n)*?(?:\Q*/\E)
#line 76 "valgol.l"
/* eat up multi-line comments */

            break;
          case 10: // rule at line 78: (?:[\x09\x0a]|\x0d|\x20)+
#line 78 "valgol.l"
/* eat up whitespace */

            break;
          case 11: // rule at line 80: (?:.[\x80-\xbf]*)
#line 80 "valgol.l"
out() << "Unrecognized character: " << text() << " at line " << lineno() << " at column " << columno() << endl;

            break;
        }
  }
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 3: user code                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 83 "valgol.l"

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