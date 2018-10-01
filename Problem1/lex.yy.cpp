// lex.yy.cpp generated by reflex 1.0.9 from vagol.l

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

#line 3 "vagol.l"

	#include <cstdio>
	#include <iostream>
	#include <iomanip>
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
 public:
  typedef reflex::AbstractLexer<reflex::Matcher> AbstractBaseLexer;
  Lexer(
      const reflex::Input& input = reflex::Input(),
      std::ostream&        os    = std::cout)
    :
      AbstractBaseLexer(input, os)
  {
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

#line 1 "vagol.l"
/* scanner for vagol language */


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 2: rules                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

int Lexer::lex()
{
  static const reflex::Pattern PATTERN_INITIAL("(?m)((?:(?:[0-9])+(?:\\x2e(?:[0-9])*)?|\\x2e(?:[0-9])+))|(if|until|do|begin|end|var|function|return)|((?:(?:[A-Z]|_|[a-z])(?:[0-9]|[A-Z]|_|[a-z])*))|((?:\"(?:.[\\x80-\\xbf]*)*?\"|'(?:.[\\x80-\\xbf]*)*?'))|((?:\\Q,\\E)|(?:\\Q;\\E)|(?:\\Q:\\E))|((?:\\Q(\\E)|(?:\\Q)\\E)|(?:\\Q[\\E)|(?:\\Q]\\E)|(?:\\Q{\\E)|(?:\\Q}\\E))|((?:\\Q+\\E)|(?:\\Q-\\E)|(?:\\Q*\\E)|(?:\\Q!\\E)|(?:\\Q->\\E)|(?:\\Q==\\E)|(?:\\Q&&\\E)|(?:\\Q||\\E))|((?:\\Q/*\\E)(?:(?:.[\\x80-\\xbf]*)|\\n)*?(?:\\Q*/\\E))|((?:[\\x09\\x0a]|\\x0d|\\x20)+)|((?:.[\\x80-\\xbf]*))");
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
          case 1: // rule at line 18: (?:(?:[0-9])+(?:\x2e(?:[0-9])*)?|\x2e(?:[0-9])+)
#line 18 "vagol.l"
{
	out() << "A real: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

            break;
          case 2: // rule at line 22: if|until|do|begin|end|var|function|return
#line 22 "vagol.l"
{
	out() << "A keyword: " << text() << " at line " << lineno() << " at column " << columno() << endl;
}

            break;
          case 3: // rule at line 26: (?:(?:[A-Z]|_|[a-z])(?:[0-9]|[A-Z]|_|[a-z])*)
#line 26 "vagol.l"
out() << "An identifier: " << text() << " at line " << lineno() << " at column " << columno() << endl;

            break;
          case 4: // rule at line 28: (?:"(?:.[\x80-\xbf]*)*?"|'(?:.[\x80-\xbf]*)*?')
#line 28 "vagol.l"
out() << "A string: " << text() << " at line " << lineno() << " at column " << columno() << endl;

            break;
          case 5: // rule at line 30: (?:\Q,\E)|(?:\Q;\E)|(?:\Q:\E)
#line 30 "vagol.l"
out() << "A punctuation mark: " << text() << " at line " << lineno() << " at column " << columno() << endl;

            break;
          case 6: // rule at line 32: (?:\Q(\E)|(?:\Q)\E)|(?:\Q[\E)|(?:\Q]\E)|(?:\Q{\E)|(?:\Q}\E)
#line 32 "vagol.l"
out() << "A delimiter:: " << text() << " at line " << lineno() << " at column " << columno() << endl;

            break;
          case 7: // rule at line 34: (?:\Q+\E)|(?:\Q-\E)|(?:\Q*\E)|(?:\Q!\E)|(?:\Q->\E)|(?:\Q==\E)|(?:\Q&&\E)|(?:\Q||\E)
#line 34 "vagol.l"
out() << "An operator: " << text() << " at line " << lineno() << " at column " << columno() << endl;

            break;
          case 8: // rule at line 36: (?:\Q/*\E)(?:(?:.[\x80-\xbf]*)|\n)*?(?:\Q*/\E)
#line 36 "vagol.l"
/* eat up multi-line comments */

            break;
          case 9: // rule at line 38: (?:[\x09\x0a]|\x0d|\x20)+
#line 38 "vagol.l"
/* eat up whitespace */

            break;
          case 10: // rule at line 40: (?:.[\x80-\xbf]*)
#line 40 "vagol.l"
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

#line 43 "vagol.l"

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
