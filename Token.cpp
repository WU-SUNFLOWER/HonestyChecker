#include "Token.h"
#include "util.h"
#include <algorithm>
#include <cassert>

Token Token::None = Token(0);
Token Token::IDF = Token(0x17F);
Token Token::STR = Token(0x180);
Token Token::EndOfLine = Token(0xFFFF);

Token::Token(uint16_t value) : _value(value) {
}

Token::Token(int value) : _value(value)
{
}

Token::Token(char value) : _value(value)
{
}

int Token::toInt() const {
	return static_cast<int>(_value);
}

void Token::print(FILE* file = stdout) const {
	int value = toInt();
	int bit8 = value & 0x80; // 0b 1000 0000
	char ch = value & 0x7F; // 0b 0111 1111

	if (*this == Token::None) {
		fprintf(file, "--");
		return;
	}
	if (*this == Token::IDF) {
		fprintf(file, "IDF");
		return;
	}
	if (*this == Token::STR) {
		fprintf(file, "STR");
		return;
	}
	if (*this == Token::EndOfLine) {
		fprintf(file, "EOL");
		return;
	}

	if (isSimpleToken()) {
		if (Util::inRange(ch, '!', '~')) {
			fprintf(file, "%s%c", (bit8 ? "8" : ""), ch);
			return;
		}
		if (Util::inRange(ch, (char)1, ' ')) {
			fprintf(file, "%s%c", (bit8 ? "$" : "^"), ch + '@');
			return;
		}
		if (ch == 0x7F) {
			fprintf(file, "%s%c", (bit8 ? "$" : "^"), '?');
			return;
		}
	}

#define check_and_print(type, ch, low, high, offset) \
	{                                                \
		char _ch = static_cast<char>(ch + offset);   \
		assert(Util::inRange(_ch, low, high));          \
		fprintf(file, "%s(%c)", type, _ch);                 \
	}

	if (isCTRL()) {
		check_and_print("CTRL", ch, 'A', '~', '@');
		return;
	}
	if (isNORM()) {
		check_and_print("NORM", ch, '!', '~', '\0');
		return;
	}
	if (isMTCT()) {
		check_and_print("MTCT", ch, 'A', '~', '@');
		return;
	}
	if (isMETA()) {
		check_and_print("META", ch, '!', '~', '\0');
		return;
	}

	printf("Unknown token 0x%x\n", value);
	exit(-1);

}

bool Token::isSimpleToken() const {
	auto value = toInt();
	return Util::inRange(value, 0x0001, 0x00FF);
}

bool Token::isCTRL() const {
	return Util::inRange(toInt(), 0x0101, 0x011E);
}

bool Token::isNORM() const {
	return Util::inRange(toInt(), 0x0121, 0x017E);
}

bool Token::isMTCT() const {
	return Util::inRange(toInt(), 0x0181, 0x019E);
}

bool Token::isMETA() const {
	return Util::inRange(toInt(), 0x01A1, 0x01FE);
}

bool operator ==(const Token& a, const Token& b) {
	return a.toInt() == b.toInt();
}

bool operator !=(const Token& a, const Token& b) {
	return a.toInt() != b.toInt();
}