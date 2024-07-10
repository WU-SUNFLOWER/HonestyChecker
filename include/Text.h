#ifndef Head_Text
#define Head_Text

#include "HonestyChecker.h"
#include <vector>
#include "Token.h"

namespace HonestyChecker {

class Text {
private:
	std::vector<Token>& _bound_vector;
	size_t _begin;
	size_t _end;
public:
	Text(std::vector<Token>& boundVector, size_t begin, size_t end);
	size_t begin() const;
	size_t end() const;
	std::vector<Token>& tokenVector();
};

}



#endif