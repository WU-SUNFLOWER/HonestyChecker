#ifndef Head_Tokenizer
#define Head_Tokenizer

#include "HonestyChecker.h"
#include "token.h"
#include "Idf.h"
#include <vector>

namespace HonestyChecker {

class Tokenizer {
private:
	size_t _currentTextPos = 0;
	size_t _beginTextPos = 0;
	size_t _lastAcceptedState = 0;
	size_t _lastAcceptedCurrentPos = 0;

	std::vector<Token>& _target;

	const uint32_t* _matrix_accept;
	const uint32_t* _matrix_ec;
	const uint32_t* _matrix_meta;
	const uint32_t* _matrix_base;
	const uint32_t* _matrix_def;
	const uint32_t* _matrix_nxt;
	const uint32_t* _matrix_chk;

	const struct Idf* _preprocess_commands;
	const struct Idf* _keywords;

	size_t _startState = 0;
	size_t _currentState = 0;
	bool _is_at_begin_of_line = true;

	const char* _text = nullptr;
	size_t _text_length = 0;
	char* _matched_text = nullptr;
	size_t _matched_text_length = 0;
	size_t _matched_text_buffer_size = 0;

	int _token_count = 0;

	Lang* _lang = nullptr;


public:

	template<typename T>
	friend class LangBase;

	//enum StartState { Initial = 0, Comment = 1 };
	enum DispatchingActionResult { Default = 0, Halt = 1, FindActionAgain = 2};

	Tokenizer(std::vector<Token>& target, Lang* lang);
	~Tokenizer();
	void initialize(const char*);
	size_t run();
	
	void setupMatchedText();
	void setStartState(int);
	void setBOL(bool bol) {
		_is_at_begin_of_line = bol;
	};

	void recordToken(Token token);
	void recordCharacter(char ch);
	void recordEOL();

	void backToPreviousState();

	void printVector(size_t begin, size_t end, FILE* file = stdout) const;

	std::vector<Token>& vector() const {
		return _target;
	};

	static Token getTokenFromIdfList(const char* idf, const struct Idf idf_list[], size_t, Token);

};

}


#endif