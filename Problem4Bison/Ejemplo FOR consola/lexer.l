%{  
	#include"bison.tab.h"
	int yylval;/*declared extern by yacc code. used to pass info to yacc*/ 
%}


%%

 /* RULES SECTION */
"*" {return MULT;}
"+" {return INC;}  
"(" {return OPBR;}
")" {return CLBR;}
[a-zA-Z]+ {yylval=yytext[0]; return ID;} 

%%

