#ifndef Head_Lang_Cpp
#define Head_Lang_Cpp

#include "Lang.h"

namespace HonestyChecker {

class LangCpp : public LangBase<LangCpp> {
protected:
	LangCpp() {};
	static Lang* instance;
public:
	static Lang* getInstance() {
		if (!instance) instance = new LangCpp();
		return instance;
	}
	size_t getLengthOfPreprocessCommandsList() override;
	size_t getLengthOfKeywordsList() override;
};

}



#endif