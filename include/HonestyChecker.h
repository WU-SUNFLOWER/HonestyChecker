#ifndef Head_HonestyChecker
#define Head_HonestyChecker

#include <cstddef>

namespace HonestyChecker {
	extern size_t MinRunSize;
	
	class Tokenizer;
	class Text;
	class Token;
	class ForwardRefMaker;
	
	class Lang;
	template<typename T>
	class LangBase;
	class LangCpp;
	class LangPython;

	struct Idf;

}

#endif
