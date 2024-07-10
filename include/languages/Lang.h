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

	virtual uint32_t getMagicNumber1() = 0;
	virtual uint32_t getMagicNumber2() = 0;

	virtual const uint32_t* getAcceptMatrix() = 0;
	virtual const uint32_t* getEquivalenceClassMatrix() = 0;
	virtual const uint32_t* getMetaMatrix() = 0;
	virtual const uint32_t* getBaseMatrix() = 0;
	virtual const uint32_t* getDefaultMatrix() = 0;
	virtual const uint32_t* getNextMatrix() = 0;
	virtual const uint32_t* getCheckMatrix() = 0;
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

	static const uint32_t Magic_Number_1;
	static const uint32_t Magic_Number_2;

	static const uint32_t Matrix_Accept[];
	static const uint32_t Matrix_Ec[];
	static const uint32_t Matrix_Meta[];
	static const uint32_t Matrix_Base[];
	static const uint32_t Matrix_Def[];
	static const uint32_t Matrix_Nxt[];
	static const uint32_t Matrix_Chk[];

	static const struct HonestyChecker::Idf Idf_PreprocessCommands[];
	static const struct HonestyChecker::Idf Idf_Keywords[];

	static const std::set<Token> Non_Initials;
	static const std::set<Token> Non_Finals;
	static const std::set<Token> Openers;
	static const std::set<Token> Closers;

public:
	virtual uint32_t getMagicNumber1() override {
		return T::Magic_Number_1;
	};
	virtual uint32_t getMagicNumber2() override {
		return T::Magic_Number_2;
	};
	virtual const uint32_t* getAcceptMatrix() override {
		return T::Matrix_Accept;
	};
	virtual const uint32_t* getEquivalenceClassMatrix() override {
		return T::Matrix_Ec;
	};
	virtual const uint32_t* getMetaMatrix() override {
		return T::Matrix_Meta;
	};
	virtual const uint32_t* getBaseMatrix() override {
		return T::Matrix_Base;
	};
	virtual const uint32_t* getDefaultMatrix() override {
		return T::Matrix_Def;
	};
	virtual const uint32_t* getNextMatrix() override {
		return T::Matrix_Nxt;
	};
	virtual const uint32_t* getCheckMatrix() override {
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