#ifndef Head_Token
#define Head_Token

#include <cstdio>
#include <cstdint>

class Token {
private:
	uint16_t _value;
public:
	Token(uint16_t);
	Token(int);
	Token(char);

	int toInt() const;

	void print(FILE* file) const;

	bool isSimpleToken() const;
	bool isCTRL() const;
	bool isNORM() const;
	bool isMTCT() const;
	bool isMETA() const;

	friend bool operator ==(const Token& a, const Token& b);
	friend bool operator !=(const Token& a, const Token& b);

	static Token None;
	static Token IDF;
	static Token STR;
	static Token EndOfLine;
};

/* Macros for the composition of tokens */		/* range (gaps unused)*/
//#define	No_Token	Token(0)			/* 0x0000 */
/* 8-bit bytes */					/* 0x0001-0x00FF */
#define	CTRL(ch)	Token(0x100|((ch)&0x01F))	/* 0x0101-0x011E */
#define	NORM(ch)	Token(0x100|((ch)&0x07F))	/* 0x0121-0x017E */
//#define	IDF		Token(0x17F)		/* 0x017F */
//#define	STR		Token(0x180)		/* 0x0180 */
#define	MTCT(ch)	Token(0x180|((ch)&0x01F))	/* 0x0181-0x019E */
#define	META(ch)	Token(0x180|((ch)&0x07F))	/* 0x01A1-0x01FE */
// tokens from Idf_Hashed()				/* 0x0200-0xFFFE */
// End_Of_Line	Token(0xFFFF)		/* 0xFFFF */

#endif