/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2022
* Author: Svillen Ranev - Paulo Sousa
* Professors: Paulo Sousa
************************************************************
 _________________________________
|                                 |
| ........ mamba LANGUAGE ........|
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
* File name: Reader.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 � Compilers, Lab Section: [011, 012, 013]
* Assignment: A12.
* Date: Sep 01 2022
* Professor: Paulo Sousa
* Purpose: This file is the main header for Reader (.h)
************************************************************
*/

/*
 *.............................................................................
 * MAIN ADVICE:
 * Please check the "TODO" labels to develop your activity.
 *.............................................................................
 */

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

 /* constant definitions */
#define RT_FAIL_1 (-1)         /* operation failure return value 1 */
#define RT_FAIL_2 (-2)         /* operation failure return value 2 */
#define LOAD_FAIL (-3)         /* load fail return value */


#ifndef READER_H_
#define READER_H_

/* TIP: Do not change pragmas, unless necessary .......................................*/
/*#pragma warning(1:4001) *//*to enforce C89 type comments  - to make //comments an warning */
/*#pragma warning(error:4001)*//* to enforce C89 comments - to make // comments an error */

/* standard header files */
#include <stdio.h>  /* standard input/output */
#include <malloc.h> /* for dynamic memory allocation*/
#include <limits.h> /* implementation-defined data type ranges and limits */

/* CONSTANTS DEFINITION: GENERAL (NOT LANGUAGE DEPENDENT) .................................. */

/* Modes (used to create buffer reader) */
enum READER_MODE {
	MODE_FIXED = 'f', /* Fixed mode (constant size) */
	MODE_ADDIT = 'a', /* Additive mode (constant increment to be added) */
	MODE_MULTI = 'm'  /* Multiplicative mode (constant increment to be multiplied) */
};

/* Constants about controls (not need to change) */
#define READER_ERROR (-1)						/* General error message */
#define READER_TERMINATOR '\0'							/* General EOF */

/* CONSTANTS DEFINITION: PREFIXED BY LANGUAGE NAME (SOFIA) .................................. */

/* You should add your own constant definitions here */
#define READER_MAX_SIZE	INT_MAX-1	/* maximum capacity */ 

#define READER_DEFAULT_SIZE			250		/* default initial buffer reader capacity */
#define READER_DEFAULT_INCREMENT	10		/* default increment factor */

/* Add your bit-masks constant definitions here - Defined for mamba */
/* BITS                                (7654.3210) */
#define READER_DEFAULT_FLAG 0x00 	/* (0000.0000)_2 = (000)_10 */
/* TO_DO: BIT 3: FUL = Full */
/* TO_DO: BIT 2: EMP: Empty */
/* TO_DO: BIT 1: REL = Relocation */
/* TO_DO: BIT 0: END = EndOfBuffer */
#define MAMBA_DEFAULT_FLAG		0xF0

#define MAMBA_SET_FLAG_RELOCATION		0x08	
#define MAMBA_SET_FLAG_FULL		0x02
#define MAMBA_SET_FLAG_EOB		0x04

#define MAMBA_CHECK_FLAG_FULL	0x02	
#define MAMBA_CHECK_FLAG_EOB		0x04
#define MAMBA_CHECK_FLAG_EMPTY	0x01	


#define MAMBA_RESET_FLAG_RELOCATION		0xF7		
#define MAMBA_RESET_FLAG_EMPTY	0xFE	
#define MAMBA_RESET_FLAG_EOB		0xFB	





#define NCHAR				128			/* Chars from 0 to 127 */

/* STRUCTURES DEFINITION: SUFIXED BY LANGUAGE NAME (SOFIA) .................................. */

/* TODO: Adjust datatypes */

/* Offset declaration */
typedef struct position {
	mamba_intg mark;			/* the offset to the mark position (in chars) */
	mamba_intg read;			/* the offset to the get a char position (in chars) */
	mamba_intg wrte;			/* the offset to the add chars (in chars) */
} Position;

/* Buffer structure */
typedef struct bufferReader {
	mamba_char* content;			/* pointer to the beginning of character array (character buffer) */
	mamba_intg	size;				/* current dynamic memory size (in bytes) allocated to character buffer */
	mamba_intg	increment;			/* character array increment factor */
	mamba_intg	mode;				/* operational mode indicator */
	mamba_byte	flags;				/* contains character array reallocation flag and end-of-buffer flag */
	Position	position;			/* Offset / position field */
	mamba_intg	histogram[NCHAR];	/* Statistics of chars */
} BufferReader, * ReaderPointer;

/* FUNCTIONS DECLARATION:  .................................. */
/* General Operations */
ReaderPointer	readerCreate(mamba_intg, mamba_intg, mamba_intg);
ReaderPointer	readerAddChar(ReaderPointer const, mamba_char);
mamba_boln		readerClear(ReaderPointer const);
mamba_boln		readerFree(ReaderPointer const);
mamba_boln		readerIsFull(ReaderPointer const);
mamba_boln		readerIsEmpty(ReaderPointer const);
mamba_boln		readerSetMark(ReaderPointer const, mamba_intg);
mamba_intg		readerPrint(ReaderPointer const);
mamba_intg		readerLoad(ReaderPointer const, FILE* const);
mamba_boln		readerRecover(ReaderPointer const);
mamba_boln		readerRetract(ReaderPointer const);
mamba_boln		readerRestore(ReaderPointer const);
/* Getters */
mamba_char		readerGetChar(ReaderPointer const);
mamba_char* readerGetContent(ReaderPointer const, mamba_intg);
mamba_intg		readerGetPosRead(ReaderPointer const);
mamba_intg		readerGetPosWrte(ReaderPointer const);
mamba_intg		readerGetPosMark(ReaderPointer const);
mamba_intg		readerGetSize(ReaderPointer const);
mamba_intg		readerGetInc(ReaderPointer const);
mamba_intg		readerGetMode(ReaderPointer const);
mamba_byte		readerGetFlags(ReaderPointer const);
mamba_intg		readerShowStat(ReaderPointer const);

#endif
