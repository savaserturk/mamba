/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2022
* Author: Svillen Ranev - Paulo Sousa
* Professors: Paulo Sousa
************************************************************
 _________________________________
|                                 |
| ........ mamba LANGUAGE ......... |
|     __    __    __    __        |
|    /  \  /  \  /  \  /  \       |
| __/  __\/  __\/  __\/  __\__    |
| _/  /__/  /__/  /__/  /_____|   |
|  \_/ \   / \   / \   / \  \___  |
|       \_/   \_/   \_/   \___o_> |
|                                 |
| .. ALGONQUIN COLLEGE - 2022F .. |
|_________________________________|

*/

/*
************************************************************
* File name: parser.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: [011, 012, 013]
* Assignment: A32.
* Date: Sep 01 2022
* Professor: Paulo Sousa
* Purpose: This file is the main header for Parser (.h)
*************************************************************/

#ifndef PARSER_H_
#define PARSER_H_

/* Inclusion section */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif
#ifndef READER_H_
#include "Reader.h"
#endif
#ifndef SCANNER_H_
#include "Scanner.h"
#endif

/* Global vars */
static Token lookahead;
extern BufferReader* stringLiteralTable;
extern mamba_intg line;
extern Token tokenizer();
extern mamba_char* keywordTable[];
mamba_intg syntaxErrorNumber = 0;

#define STR_LANGNAME	"mamba"
#define LANG_WRTE		"print"
#define LANG_READ		"input"
#define LANG_MAIN		"main"

/* TO_DO: Create ALL constants for keywords (sequence given in table.h) */

/* Constants */
enum KEYWORDS {
	NO_ATTR = -1,
	KW_if,
	KW_then,
	KW_else,
	KW_while,
	KW_do,
	KW_def,
	KW_and,
	KW_or,
	KW_re,
	KW_not,
	KW_True,
	KW_False
};

/* Function definitions */
mamba_void startParser();
mamba_void matchToken(mamba_intg, mamba_intg);
mamba_void syncErrorHandler(mamba_intg);
mamba_void printError();

/* TO_DO: Place ALL non-terminal function declarations */



mamba_void program();

mamba_void statement();
mamba_void statements();
mamba_void statementsPrime();

mamba_void functionDeclaration();
mamba_void functionInvocation();

mamba_void optVariableList();
mamba_void variableList();
mamba_void variable();
mamba_void variableListPrime();

mamba_void outputStatement();

mamba_void inputStatement();
mamba_void assignmentStatement();

mamba_void variable_expressions();
mamba_void variable_expression();
mamba_void variable_expressions_prime();


mamba_void arithmetic_expression();
mamba_void unary_arithmetic_expression();
mamba_void addition_arithmetic_expression();
mamba_void multiplication_arithmetic_expression();
mamba_void primary_arithmetic_expression();


mamba_void string_expression();

mamba_void conditional_expressions();
mamba_void conditional_expression();
mamba_void conditional_expressions_prime();

mamba_void logical_and_expression();
mamba_void logical_or_expression();
mamba_void relational_expression();

mamba_void returnStatement();

#endif
