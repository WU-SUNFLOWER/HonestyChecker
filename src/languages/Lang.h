#ifndef Head_Lang
#define Head_Lang

#include "HonestyChecker.h"
#include "Idf.h"
#include "Token.h"
#include "Tokenizer.h"
#include <set>

namespace HonestyChecker {

class Lang {
protected:
	Lang() {};
public:
	virtual ~Lang() = default;

	virtual int getMagicNumber1() = 0;
	virtual int getMagicNumber2() = 0;

	virtual const int* getAcceptMatrix() = 0;
	virtual const int* getEquivalenceClassMatrix() = 0;
	virtual const int* getMetaMatrix() = 0;
	virtual const int* getBaseMatrix() = 0;
	virtual const int* getDefaultMatrix() = 0;
	virtual const int* getNextMatrix() = 0;
	virtual const int* getCheckMatrix() = 0;
	virtual const struct HonestyChecker::Idf* getPreprocessCommands() = 0;
	virtual const struct HonestyChecker::Idf* getKeywords() = 0;
	virtual size_t getLengthOfPreprocessCommandsList() = 0;
	virtual size_t getLengthOfKeywordsList() = 0;

	virtual bool isNotFinal(const Token&) = 0;
	virtual bool isNotInitial(const Token&) = 0;
	virtual bool isOpener(const Token&) = 0;
	virtual bool isCloser(const Token&) = 0;

	virtual Tokenizer::DispatchingActionResult dispatchActionForTokenizer(
		Tokenizer* tokenizer, int action) = 0;
};

template<typename T>
class LangBase : public Lang {
protected:

	static const int Magic_Number_1;
	static const int Magic_Number_2;

	static const int Matrix_Accept[];
	static const int Matrix_Ec[];
	static const int Matrix_Meta[];
	static const int Matrix_Base[];
	static const int Matrix_Def[];
	static const int Matrix_Nxt[];
	static const int Matrix_Chk[];

	static const struct HonestyChecker::Idf Idf_PreprocessCommands[];
	static const struct HonestyChecker::Idf Idf_Keywords[];

	static const std::set<Token> Non_Initials;
	static const std::set<Token> Non_Finals;
	static const std::set<Token> Openers;
	static const std::set<Token> Closers;

public:
	virtual int getMagicNumber1() override {
		return T::Magic_Number_1;
	};
	virtual int getMagicNumber2() override {
		return T::Magic_Number_2;
	};
	virtual const int* getAcceptMatrix() override {
		return T::Matrix_Accept;
	};
	virtual const int* getEquivalenceClassMatrix() override {
		return T::Matrix_Ec;
	};
	virtual const int* getMetaMatrix() override {
		return T::Matrix_Meta;
	};
	virtual const int* getBaseMatrix() override {
		return T::Matrix_Base;
	};
	virtual const int* getDefaultMatrix() override {
		return T::Matrix_Def;
	};
	virtual const int* getNextMatrix() override {
		return T::Matrix_Nxt;
	};
	virtual const int* getCheckMatrix() override {
		return T::Matrix_Chk;
	};
	virtual const struct HonestyChecker::Idf* getPreprocessCommands() override {
		return T::Idf_PreprocessCommands;
	};
	virtual const struct HonestyChecker::Idf* getKeywords() override {
		return T::Idf_Keywords;
	};
	virtual bool isNotInitial(const Token& token) override {
		return T::Non_Initials.find(token) != T::Non_Initials.end();
	};
	virtual bool isNotFinal(const Token& token) override {
		return T::Non_Finals.find(token) != T::Non_Finals.end();
	};
	virtual bool isOpener(const Token& token) override {
		return T::Openers.find(token) != T::Openers.end();
	};
	virtual bool isCloser(const Token& token) override {
		return T::Closers.find(token) != T::Closers.end();
	};
	virtual Tokenizer::DispatchingActionResult dispatchActionForTokenizer(
		Tokenizer* tokenizer, int action) override;
};

}

#endif