#ifndef Head_Token
#define Head_Token

#include <cstdint>

typedef uint16_t Token;

/* Conversion routines */
#define	Token_To_Int(c)	((int)(c))
#define	Int_To_Token(i)	((Token)(i))
#define	Token_EQ(t1,t2)	(Token_To_Int(t1) == Token_To_Int(t2))

/* Macros for the composition of tokens */		/* range (gaps unused)*/
#define	No_Token	Int_To_Token(0)			/* 0x0000 */
/* 8-bit bytes */					/* 0x0001-0x00FF */
#define	CTRL(ch)	Int_To_Token(0x100|((ch)&0x01F))	/* 0x0101-0x011E */
#define	NORM(ch)	Int_To_Token(0x100|((ch)&0x07F))	/* 0x0121-0x017E */
#define	IDF		Int_To_Token(0x17F)		/* 0x017F */
#define	STR		Int_To_Token(0x180)		/* 0x0180 */
#define	MTCT(ch)	Int_To_Token(0x180|((ch)&0x01F))	/* 0x0181-0x019E */
#define	META(ch)	Int_To_Token(0x180|((ch)&0x07F))	/* 0x01A1-0x01FE */
/* tokens from Idf_Hashed() */				/* 0x0200-0xFFFE */
#define	End_Of_Line	Int_To_Token(0xFFFF)		/* 0xFFFF */


#endif