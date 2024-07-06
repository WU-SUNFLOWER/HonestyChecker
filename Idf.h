#ifndef Head_Idf
#define Head_Idf

#include "token.h"

struct Idf {
	const char* id_tag;	/* an interesting identifier */
	Token id_tr;	/* with its one-Token translation */
};
#endif