#ifndef Head_Tokenizer
#define Head_Tokenizer

#include "token.h"
#include "Idf.h"
#include <vector>

class Tokenizer {
private:
	static const int Matrix_Cpp_Accept[];
	static const int Matrix_Cpp_Ec[];
	static const int Matrix_Cpp_Meta[];
	static const int Matrix_Cpp_Base[];
	static const int Matrix_Cpp_Def[];
	static const int Matrix_Cpp_Nxt[];
	static const int Matrix_Cpp_Chk[];

	static const struct Idf Idf_Cpp_PreprocessCommands[];
	static const struct Idf Idf_Cpp_Keywords[];

	enum StartState { Initial = 0, Comment = 1};

private:
	char* _text;
	int _text_length;

	int _currentTextPos;
	int _beginTextPos;

	std::vector<Token>& _target;

	const int* _matrix_accept;
	const int* _matrix_ec;
	const int* _matrix_meta;
	const int* _matrix_base;
	const int* _matrix_def;
	const int* _matrix_nxt;
	const int* _matrix_chk;

	int _startState;
	int _currentState;
	bool _is_at_begin_of_line;

	char* _matched_text = nullptr;
	char _backup_char;
	int _matched_text_length;

public:
	Tokenizer(char* text, int text_length, std::vector<Token>& target, int type);
	
	void run();
	
	void setupMatchedText();
	void setStartState(Tokenizer::StartState);
	void setBOL(bool bol) {
		_is_at_begin_of_line = bol;
	};

	void recordToken(Token token);
	void recordCharacter(char ch);
	void recordEOL();

	char* getMatchedText() {
		return _matched_text;
	}
	int getMatchedTextLength() {
		return _matched_text_length;
	}

	static Token getTokenFromIdfList(const char* idf, const struct Idf idf_list[], size_t, Token);
};
#endif