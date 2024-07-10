#include "Text.h"
#include <cassert>

using namespace HonestyChecker;

Text::Text(std::vector<Token>& boundVector, size_t begin, size_t end) 
	: _bound_vector(boundVector), _begin(begin), _end(end)
{
	assert(end <= boundVector.size());
}

size_t Text::begin() const {
	return _begin;
}

size_t Text::end() const {
	return _end;
}

std::vector<Token>& Text::tokenVector() {
	return _bound_vector;
}
