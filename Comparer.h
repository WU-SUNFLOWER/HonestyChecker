#ifndef Head_Comparer
#define Head_Comparer

#include <vector>
#include "Token.h"
#include "Text.h"

class Comparer {
private:
	std::vector<Token>& _token_vector;
	std::vector<Text>& _texts;
	size_t* _forward_reference = nullptr;
public:
	Comparer(std::vector<Token>& vec, std::vector<Text>& texts);
	~Comparer();
	double run();
	size_t lcs(Text&, size_t i0);
};

#endif