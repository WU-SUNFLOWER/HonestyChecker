#ifndef Head_Lang_Python
#define Head_Lang_Python

#include "Lang.h"

namespace HonestyChecker {

	class LangPython : public LangBase<LangPython> {
	protected:
		LangPython() {};
		static Lang* instance;
	public:
		static Lang* getInstance() {
			if (!instance) instance = new LangPython();
			return instance;
		}
		size_t getLengthOfPreprocessCommandsList() override;
		size_t getLengthOfKeywordsList() override;
	};

}



#endif