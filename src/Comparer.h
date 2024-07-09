#ifndef Head_Comparer
#define Head_Comparer

#include "HonestyChecker.h"
#include <vector>
#include "Token.h"
#include "Text.h"
#include "Lang.h"

namespace HonestyChecker {

class Comparer {
private:
	std::vector<Token>& _token_vector;
	std::vector<Text>& _texts;
	size_t* _forward_reference = nullptr;
	Lang* _lang;
public:
	Comparer(std::vector<Token>& vec, std::vector<Text>& texts, Lang*);
	~Comparer();
	double run();
	size_t lcs(Text&, size_t i0);
};

}

#endif