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

	int _startState;
	int _currentState;
	bool _is_at_begin_of_line;

	const char* _text;
	size_t _text_length;
	char* _matched_text = nullptr;
	size_t _matched_text_length;
	size_t _matched_text_buffer_size;

public:
	Tokenizer(const char* text, size_t text_length, std::vector<Token>& target, int type);
	~Tokenizer();

	void run();
	
	void setupMatchedText();
	void setStartState(Tokenizer::StartState);
	void setBOL(bool bol) {
		_is_at_begin_of_line = bol;
	};

	void recordToken(Token token);
	void recordCharacter(char ch);
	void recordEOL();

	void backToPreviousState();

	static Token getTokenFromIdfList(const char* idf, const struct Idf idf_list[], size_t, Token);

};
#endif