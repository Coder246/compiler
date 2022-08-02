//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_KEYWORDS_H
#define COMPILER_KEYWORDS_H

#include "Keyword.h"

Keyword KEYWORD_IF = Keyword("if");
Keyword KEYWORD_ELSE = Keyword("else");
Keyword KEYWORD_WHILE = Keyword("while");
Keyword KEYWORD_DO = Keyword("do");
Keyword KEYWORD_FOR = Keyword("for");
Keyword KEYWORD_RETURN = Keyword("return");
Keyword KEYWORD_BREAK = Keyword("break");
Keyword KEYWORD_CONTINUE = Keyword("continue");
Keyword KEYWORD_FUNCTION = Keyword("function");
Keyword KEYWORD_VAR = Keyword("var");
Keyword KEYWORD_TRUE = Keyword("true");
Keyword KEYWORD_FALSE = Keyword("false");
Keyword KEYWORD_NULL = Keyword("null");
Keyword KEYWORD_NEW = Keyword("new");
Keyword KEYWORD_THIS = Keyword("this");
Keyword KEYWORD_CLASS = Keyword("class");
Keyword KEYWORD_VOID = Keyword("void");


//array of all keywords
Keyword *KEYWORDS[] = {
        &KEYWORD_IF,
        &KEYWORD_ELSE,
        &KEYWORD_WHILE,
        &KEYWORD_RETURN,
        &KEYWORD_BREAK,
        &KEYWORD_CONTINUE,
        &KEYWORD_FOR,
        &KEYWORD_DO,
        &KEYWORD_FUNCTION,
        &KEYWORD_VAR,
        &KEYWORD_TRUE,
        &KEYWORD_FALSE,
        &KEYWORD_NULL,
        &KEYWORD_NEW,
        &KEYWORD_THIS,
        &KEYWORD_CLASS,
        &KEYWORD_VOID
};



#endif //COMPILER_KEYWORDS_H
