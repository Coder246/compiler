cmake_minimum_required(VERSION 3.22)
project(compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(compiler main.cpp Lexer.cpp Token.cpp Keyword.cpp Parser.cpp statements/IFStatement.cpp statements/IFStatement.h expressions/Expression.h expressions/Condition.cpp expressions/Condition.h expressions/Variable.cpp expressions/Variable.h statements/Assignment.cpp statements/Assignment.h expressions/Expression.cpp expressions/Expression.h statements/Statement.cpp statements/Statement.h statements/Return.cpp statements/Return.h expressions/Constant.cpp expressions/Constant.h expressions/Term.cpp expressions/Term.h)
