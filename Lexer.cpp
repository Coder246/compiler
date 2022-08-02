//
// Created by tim on 02.08.22.
//

#include <string>
#include <iostream>
#include "Lexer.h"
#include "Keywords.h"

void Lexer::lex(const std::string &input) {
    this->length = input.length();
    this->source = input;

    while (this->counter < this->length) {
        char c = this->currentChar();
        if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == ';') {
            this->next();
        } else if (c == '{') {
            this->checkBraceStack(c, true, TokenType::TOKEN_LEFT_CURLY, TokenType::TOKEN_RIGHT_CURLY);
            this->addToken(TokenType::TOKEN_LEFT_CURLY, "{");
            this->next();
        } else if (c == '}') {
            this->checkBraceStack(c, false, TokenType::TOKEN_RIGHT_CURLY, TokenType::TOKEN_LEFT_CURLY);
            this->addToken(TokenType::TOKEN_RIGHT_CURLY, "}");
            this->next();
        } else if (c == '(') {
            this->checkBraceStack(c, true, TokenType::TOKEN_LEFT_BRACKET, TokenType::TOKEN_RIGHT_BRACKET);
            this->addToken(TokenType::TOKEN_LEFT_BRACKET, "(");
            this->next();

        } else if (c == ')') {
            this->checkBraceStack(c, false, TokenType::TOKEN_RIGHT_BRACKET, TokenType::TOKEN_LEFT_BRACKET);
            this->addToken(TokenType::TOKEN_RIGHT_BRACKET, ")");
            this->next();

        } else if (c == '[') {
            this->checkBraceStack(c, true, TokenType::TOKEN_LEFT_SQUARE_BRACKET, TokenType::TOKEN_RIGHT_SQUARE_BRACKET);
            this->addToken(TokenType::TOKEN_LEFT_SQUARE_BRACKET, "[");
            this->next();

        } else if (c == ']') {
            this->checkBraceStack(c, false, TokenType::TOKEN_RIGHT_SQUARE_BRACKET,
                                  TokenType::TOKEN_LEFT_SQUARE_BRACKET);
            this->addToken(TokenType::TOKEN_RIGHT_SQUARE_BRACKET, "]");
            this->next();

        } else if (c == '/') {
            if (this->nextChar() == '/') {
                this->skipLine();
            } else if (this->nextChar() == '*') {
                std::string comment = this->moveCursorToNextString("*/", false);
                if (comment.find("*/") == std::string::npos) {
                    std::cout << "WARN: Unclosed comment" << std::endl;
                } else if (this->nextChar() == '=') {
                    this->addToken(TokenType::TOKEN_SLASH_EQUAL, "/=");
                    this->next();
                    this->next();
                } else {
                    this->addToken(TokenType::TOKEN_SLASH, "/");
                    this->next();
                }


            } else {
                this->addToken(TokenType::TOKEN_SLASH, "/");
                this->next();
            }

        } else if (c == '*') {
            if (this->nextChar() == '/') {
                //warn about unopend comment
                std::cout << "WARN: Unopened comment at " << this->line << ":" << this->pos << std::endl;
                this->next();
                this->next();
            } else if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_STAR_EQUAL, "*=");
                this->next();
                this->next();
            } else {
                this->addToken(TokenType::TOKEN_STAR, "*");
                this->next();
            }

        } else if (c == '+') {
            if (this->nextChar() == '+') {
                this->addToken(TokenType::TOKEN_PLUS_PLUS, "++");
                this->next();
                this->next();
            } else if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_PLUS_EQUAL, "+=");
                this->next();
                this->next();
            } else {
                this->addToken(TokenType::TOKEN_PLUS, "+");
                this->next();
            }
        } else if (c == '-') {
            if (this->nextChar() == '-') {
                this->addToken(TokenType::TOKEN_MINUS_MINUS, "--");
                this->next();
                this->next();
            } else if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_MINUS_EQUAL, "-=");
                this->next();
                this->next();
            } else {
                this->addToken(TokenType::TOKEN_MINUS, "-");
                this->next();
            }
        } else if (c == '%') {
            if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_MODULO_EQUAL, "%=");
                this->next();
                this->next();
            } else {
                this->addToken(TokenType::TOKEN_MODULO, "%");
                this->next();
            }


        } else if (c == '=') {
            if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_EQUAL, "==");
                this->next();
                this->next();
            } else {
                this->addToken(TokenType::TOKEN_SET, "=");
                this->next();
            }
        } else if (c == '!') {
            if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_NOT_EQUAL, "!=");
                this->next();
                this->next();
            } else {
                this->addToken(TokenType::TOKEN_BITWISE_NOT, "!");
                this->next();
            }

        } else if (c == '&') {
            if (this->nextChar() == '&') {
                this->addToken(TokenType::TOKEN_AND, "&&");
                this->next();
                this->next();
            } else if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_BITWISE_AND_EQUAL, "&=");
                this->next();
                this->next();
            } else {
                this->addToken(TokenType::TOKEN_BITWISE_AND, "&");
                this->next();
            }

        } else if (c == '|') {
            if (this->nextChar() == '|') {
                this->addToken(TokenType::TOKEN_OR, "||");
                this->next();
                this->next();
            } else if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_BITWISE_OR_EQUAL, "|=");
                this->next();
                this->next();
            } else {
                this->addToken(TokenType::TOKEN_BITWISE_OR, "|");
                this->next();
            }

        } else if (c == '<') {
            if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_LESS_THAN_EQUAL, "<=");
                this->next();
                this->next();
            } else if (this->nextChar() == '<') {
                this->next();
                if (this->nextChar() == '=') {
                    this->addToken(TokenType::TOKEN_SHIFT_LEFT_EQUAL, "<<=");
                    this->next();
                } else {
                    this->addToken(TokenType::TOKEN_SHIFT_LEFT, "<<");
                }

                this->next();
            } else {
                this->addToken(TokenType::TOKEN_LESS_THAN, "<");
                this->next();
            }

        } else if (c == '>') {
            if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_GREATER_THAN_EQUAL, ">=");
                this->next();
                this->next();
            } else if (this->nextChar() == '>') {
                this->next();
                if (this->nextChar() == '=') {
                    this->addToken(TokenType::TOKEN_SHIFT_RIGHT_EQUAL, ">>=");
                    this->next();
                } else {
                    this->addToken(TokenType::TOKEN_SHIFT_RIGHT, ">>");
                }

                this->next();
            } else {
                this->addToken(TokenType::TOKEN_GREATER_THAN, ">");
                this->next();
            }

        } else if (c == '^') {
            if (this->nextChar() == '=') {
                this->addToken(TokenType::TOKEN_BITWISE_XOR_EQUAL, "^=");
                this->next();
                this->next();
            } else {
                this->addToken(TokenType::TOKEN_BITWISE_XOR, "^");
                this->next();
            }

        } else if (this->charIsDigit(c)) {

            std::string num = "";
            int countDot = 0, countExp = 0;
            while (this->charIsDigit(c) || c == '.' || c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'l' ||
                   c == 'L') {


                if (c == '.') {
                    if (countDot > 0) {
                        std::cout << "ERROR: Unexpected . at " << this->line << ":" << this->pos << std::endl;
                        break;
                    }
                    countDot++;
                } else if (c == 'e' || c == 'E') {
                    if (countExp > 0) {
                        std::cout << "ERROR: Unexpected e at " << this->line << ":" << this->pos << std::endl;
                        break;
                    }
                    countExp++;
                }
                num += c;
                this->next();
                c = this->currentChar();
            }
            this->addToken(TokenType::TOKEN_NUMBER, num);

        } else if (c == '"') {

            int stringBegin = this->pos, stringBeginLine = this->line;
            this->next();
            std::string foundString = this->moveCursorToChar('"', true);
            if (foundString.find('\"') == std::string::npos) {
                std::cout << "ERROR: Cannot find end of string " << stringBeginLine << ":" << stringBegin << std::endl;
            }
            this->addToken(TokenType::TOKEN_STRING, "\"" + foundString);
        } else if (c == '\'') {
            this->next();
            if (this->nextChar() == '\'') {
                this->addToken(TokenType::TOKEN_CHAR, "\'" + std::string(1, this->currentChar()) + "\'");
                this->next();
                this->next();
            } else {
                std::cout << "ERROR: Cannot find end of char " << this->line << ":" << this->pos << std::endl;
                this->next();
            }

        }else if(this->charIsAlpha(c)|| c == '_') {
            std::string identifier = "";
            while (this->charIsAlphaNumeric(c) || c == '_') {
                identifier += c;
                this->next();
                c = this->currentChar();
            }
            this->filterKeywords(identifier);
        } else {
            this->next();
        }

    }

    if (!this->braceStack.empty()) {
        //iterate over stack and print all braces that are not closed
        while (!this->braceStack.empty()) {
            Token token = this->braceStack.top();
            std::cout << "ERROR: Unclosed brace at " << token.getLine() <<":"<< token.getPos() << std::endl;
            this->braceStack.pop();
        }
    }

}


std::vector<Token> Lexer::getTokens() {
    return this->tokens;
}

void Lexer::printTokens() {
    for (Token token: this->tokens) {
        std::cout << token.toString() << std::endl;
    }

    std::cout << "Total Tokens: " << this->tokens.size() << std::endl;

}

char Lexer::nextChar() {

    if (this->counter+1 >= this->source.length()) {
        return 0x04;
    }

    char c = this->source[this->counter + 1];
    return c;
}

bool Lexer::next() {

    if (this->source[this->counter] == '\n') {
        this->line++;
        this->pos = 0;
    } else {
        this->pos++;
    }

    this->counter++;

    if (this->counter >= this->source.length()) {
        return false;
    }




    return true;


}

void Lexer::addToken(TokenType type, std::string value) {
    this->tokens.push_back(Token(type, value, this->line, this->pos));

}

std::string Lexer::moveCursorToChar(char end, bool LFStop) {
    std::string result = "";
    while (this->source[this->counter] != end) {
        result += this->source[this->counter];
        this->next();
        if (LFStop && this->source[this->counter] == '\n') {
            break;
        }
    }

    if (this->source.find(end, this->counter) == this->counter) {
        //add the end string to the result
        result += end;
        //set the counter to the end of the string
        this->counter += 1;
    }

    return result;
}

void Lexer::checkBraceStack(char brace, bool isLeft, TokenType tokenType, TokenType correspondingToken) {
    if (isLeft) {
        this->braceStack.push(Token(tokenType, &""[brace], this->line, this->pos));
    } else {
        if (this->braceStack.size() == 0) {
            std::cout << "ERROR: Unexpected '" << brace << "' at " << this->line << ":" << this->pos << std::endl;
            // exit(EXIT_FAILURE);
        } else {
            //check if the last token is a left curly
            if (this->braceStack.top().getType() == correspondingToken) {
                this->braceStack.pop();
            } else {
                std::cout << "ERROR: Unexpected '" << brace << "' at " << this->line << ":" << this->pos << std::endl;
                // exit(EXIT_FAILURE);
            }

        }
    }

}

void Lexer::skipLine() {
    while (this->source[this->counter] != '\n') {
        this->next();
    }
}

char Lexer::currentChar() {
    char c = this->source[this->counter];
    return c;
}

std::string Lexer::moveCursorToNextString(std::string endString, bool LFStop) {
    std::string result = "";
    while (this->source.find(endString, this->counter) != this->counter) {
        result += this->source[this->counter];
        if (!this->next()) {
            break;
        }
        if (LFStop && this->source[this->counter] == '\n') {
            break;
        }
    }


    if (this->source.find(endString, this->counter) == this->counter) {
        //add the end string to the result
        result += endString;
        //set the counter to the end of the string
        this->counter += endString.length();
    }

    return result;
}

bool Lexer::charIsDigit(char c) {
    return c >= '0' && c <= '9';
}

bool Lexer::charIsAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Lexer::charIsAlphaNumeric(char i) {
    return this->charIsDigit(i) || this->charIsAlpha(i);
}

void Lexer::filterKeywords(std::string identifier) {

    for (Keyword *item: KEYWORDS) {
        if (identifier == item->getValue()) {
            this->addToken(TokenType::TOKEN_KEYWORD, item->getValue());
            return;
        }
    }
    this->addToken(TokenType::TOKEN_IDENTIFIER, identifier);
}



