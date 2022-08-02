//
// Created by tim on 02.08.22.
//

#ifndef COMPILER_KEYWORDS_H
#define COMPILER_KEYWORDS_H

#include "Keyword.h"

static Keyword KEYWORD_IF = Keyword("if");
static Keyword KEYWORD_ELSE = Keyword("else");
static Keyword KEYWORD_WHILE = Keyword("while");
static Keyword KEYWORD_DO = Keyword("do");
static Keyword KEYWORD_FOR = Keyword("for");
static Keyword KEYWORD_RETURN = Keyword("return");
static Keyword KEYWORD_BREAK = Keyword("break");
static Keyword KEYWORD_CONTINUE = Keyword("continue");
static Keyword KEYWORD_FUNCTION = Keyword("function");
static Keyword KEYWORD_VAR = Keyword("var");
static Keyword KEYWORD_TRUE = Keyword("true");
static Keyword KEYWORD_FALSE = Keyword("false");
static Keyword KEYWORD_NULL = Keyword("null");
static Keyword KEYWORD_NEW = Keyword("new");
static Keyword KEYWORD_THIS = Keyword("this");
static Keyword KEYWORD_CLASS = Keyword("class");
static Keyword KEYWORD_VOID = Keyword("void");


//array of all keywords
static Keyword *KEYWORDS[] = {
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
