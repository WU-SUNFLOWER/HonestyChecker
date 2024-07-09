#ifndef Head_Tokenizer
#define Head_Tokenizer

#include "HonestyChecker.h"
#include "token.h"
#include "Idf.h"
#include <vector>

namespace HonestyChecker {

class Tokenizer {
private:

	Lang* _lang;

	int _currentTextPos;
	int _beginTextPos;
	int _lastAcceptedState;
	int _lastAcceptedCurrentPos;

	std::vector<Token>& _target;

	const int* _matrix_accept;
	const int* _matrix_ec;
	const int* _matrix_meta;
	const int* _matrix_base;
	const int* _matrix_def;
	const int* _matrix_nxt;
	const int* _matrix_chk;

	const struct Idf* _preprocess_commands;
	const struct Idf* _keywords;

	int _startState;
	int _currentState;
	bool _is_at_begin_of_line;

	const char* _text;
	size_t _text_length;
	char* _matched_text = nullptr;
	size_t _matched_text_length;
	size_t _matched_text_buffer_size;

	int _token_count;

public:

	template<typename T>
	friend class LangBase;

	//enum StartState { Initial = 0, Comment = 1 };
	enum DispatchingActionResult { Default = 0, Halt = 1, FindActionAgain = 2};

	Tokenizer(const char* text, size_t text_length, std::vector<Token>& target, Lang* lang);
	~Tokenizer();

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

	static Token getTokenFromIdfList(const char* idf, const struct Idf idf_list[], size_t, Token);

};

}


#endif