#ifndef Head_Token
#define Head_Token

#include "HonestyChecker.h"
#include <cstdio>
#include <cstdint>

namespace HonestyChecker {

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

	static Token None;
	static Token IDF;
	static Token STR;
	static Token EndOfLine;

	bool operator <(const Token& other) const;
};

}

bool operator ==(const HonestyChecker::Token& a, const HonestyChecker::Token& b);
bool operator !=(const HonestyChecker::Token& a, const HonestyChecker::Token& b);

/* Macros for the composition of tokens */		/* range (gaps unused)*/
//#define	No_Token	Token(0)			/* 0x0000 */
/* 8-bit bytes */					/* 0x0001-0x00FF */
#define	CTRL(ch)	HonestyChecker::Token(0x100|((ch)&0x01F))	/* 0x0101-0x011E */
#define	NORM(ch)	HonestyChecker::Token(0x100|((ch)&0x07F))	/* 0x0121-0x017E */
//#define	IDF		Token(0x17F)		/* 0x017F */
//#define	STR		Token(0x180)		/* 0x0180 */
#define	MTCT(ch)	HonestyChecker::Token(0x180|((ch)&0x01F))	/* 0x0181-0x019E */
#define	META(ch)	HonestyChecker::Token(0x180|((ch)&0x07F))	/* 0x01A1-0x01FE */
// tokens from Idf_Hashed()				/* 0x0200-0xFFFE */
// End_Of_Line	Token(0xFFFF)		/* 0xFFFF */

#endif