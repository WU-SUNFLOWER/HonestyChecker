#ifndef Head_ForwardRefMaker
#define Head_ForwardRefMaker

#include "Text.h"
#include <vector>

class ForwardRefMaker {
private:

	static int shift;
	static size_t prime[];

	std::vector<Text>& _texts;
	std::vector<Token>& _vector;
	size_t _vector_length;

	size_t* _forward_reference = nullptr;
	size_t* _latest_index = nullptr; // our hash table
	size_t _hash_table_size = 0;
public:
	ForwardRefMaker(std::vector<Text>&, std::vector<Token>&);
	~ForwardRefMaker();

	bool isEqualMinRun(size_t i, size_t j);

	size_t* run();

	const size_t* result() const;
};

#endif