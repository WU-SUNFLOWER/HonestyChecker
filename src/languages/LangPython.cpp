#include "LangPython.h"

using namespace HonestyChecker;

template<>
const uint32_t LangBase<LangPython>::Magic_Number_1 = 80;
template<>
const uint32_t LangBase<LangPython>::Magic_Number_2 = 245;

template<>
const uint32_t LangBase<LangPython>::Matrix_Accept[] =
{ 0,
    0,    0,    0,    0,    0,    0,   18,   16,   14,   13,
   14,   15,   15,   15,   15,   11,   11,   12,   10,   10,
   10,   10,   10,   10,   17,   17,   17,    0,    6,    0,
    0,    5,    0,    7,    0,   11,   11,    0,   10,   10,
    0,    0,   10,   10,    0,    0,    6,    1,    7,    3,
   10,   10,    2,    4,   10,   10,    0,   10,    8,   10,
    0,    8,    0,    8,    9,    8,    0,    0,    0,    9,
    0,    9,    9,    0,    9,    9,    9,    9,    0
};

template<>
const uint32_t LangBase<LangPython>::Matrix_Ec[] =
{ 0,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
    1,    2,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    4,    5,    6,    7,    5,    5,    5,    8,    5,
    5,    5,    5,    9,    5,   10,    5,   11,   12,   12,
   12,   12,   12,   12,   12,   12,   12,    5,   13,    5,
    5,    5,    5,    5,   14,   14,   14,   14,   14,   14,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
    5,   16,    5,    5,   15,    5,   14,   17,   14,   14,

   14,   18,   15,   15,   19,   15,   15,   15,   20,   15,
   21,   22,   15,   23,   15,   24,   25,   15,   15,   26,
   15,   15,    5,    5,    5,    5,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1
};

template<>
const uint32_t LangBase<LangPython>::Matrix_Meta[] =
{ 0,
    1,    2,    3,    2,    1,    1,    1,    1,    4,    5,
    6,    6,    1,    7,    8,    1,    7,    7,    8,    8,
    8,    8,    8,    8,    8,    7
};

template<>
const uint32_t LangBase<LangPython>::Matrix_Base[] =
{ 0,
    0,    0,  109,  108,  105,  104,  110,  245,  245,  245,
  245,  245,   21,  103,   20,   12,   79,  245,   28,    0,
   41,   81,   83,   24,  245,   95,   89,   25,   90,    0,
   92,  245,   27,   86,    0,    0,    0,    0,   42,    0,
   28,   46,   71,   66,   81,   78,  245,  245,  245,  245,
   60,   51,  245,  245,   59,   46,   62,   36,   47,   63,
    0,   46,   66,   41,   69,   23,   72,   73,    0,   80,
   81,   89,   98,    0,  107,  116,  125,  134,  245,  144,
  152,  160,  168,  171,  173,  180,  184,  186,  193,  197,
  204,  211,  213,  220,  227,  229,  236

};

template<>
const uint32_t LangBase<LangPython>::Matrix_Def[] =
{ 0,
   79,    1,   80,   80,   80,   80,   79,   79,   79,   79,
   79,   79,   81,   82,   83,   84,   84,   79,   85,   85,
   85,   21,   85,   85,   79,   79,   79,   81,   79,   81,
   82,   79,   83,   79,   83,   17,   17,   17,   21,   85,
   81,   83,   85,   85,   79,   79,   79,   79,   79,   79,
   85,   85,   79,   79,   85,   85,   86,   85,   87,   85,
   88,   87,   89,   90,   91,   90,   79,   92,   93,   91,
   92,   94,   95,   96,   94,   95,   97,   97,    0,   79,
   79,   79,   79,   79,   79,   79,   79,   79,   79,   79,
   79,   79,   79,   79,   79,   79,   79

};

template<>
const uint32_t LangBase<LangPython>::Matrix_Nxt[] =
{ 0,
    8,    9,   10,   11,   12,   13,   14,   15,   12,   12,
   16,   17,   18,   19,   20,   12,   21,   22,   23,   20,
   20,   20,   24,   20,   24,   20,   29,   34,   37,   41,
   47,   42,   61,   47,   49,   35,   30,   38,   39,   39,
   30,   39,   35,   30,   39,   39,   41,   79,   42,   79,
   61,   39,   39,   49,   39,   61,   61,   39,   39,   60,
   57,   35,   57,   57,   63,   57,   63,   63,   58,   63,
   67,   56,   67,   67,   71,   67,   71,   68,   69,   55,
   68,   67,   71,   67,   71,   54,   53,   52,   68,   69,
   67,   51,   67,   50,   32,   48,   46,   68,   74,   67,

   45,   67,   44,   43,   79,   32,   68,   69,   67,   79,
   67,   27,   27,   26,   26,   68,   74,   67,   79,   67,
   79,   79,   79,   79,   68,   69,   67,   79,   67,   79,
   79,   79,   79,   68,   74,   67,   79,   67,   79,   79,
   79,   79,   68,   74,   25,   25,   25,   25,   25,   25,
   25,   25,   28,   28,   79,   28,   28,   28,   28,   28,
   31,   31,   31,   31,   31,   31,   31,   31,   33,   33,
   79,   33,   33,   33,   33,   33,   36,   36,   40,   40,
   40,   59,   79,   79,   79,   79,   59,   59,   62,   62,
   62,   62,   64,   64,   65,   79,   79,   79,   79,   65,

   65,   66,   66,   66,   66,   70,   79,   70,   70,   70,
   70,   70,   72,   79,   79,   79,   79,   72,   72,   73,
   73,   75,   79,   75,   75,   75,   75,   75,   76,   79,
   76,   76,   76,   76,   76,   77,   77,   78,   79,   78,
   78,   78,   78,   78,    7,   79,   79,   79,   79,   79,
   79,   79,   79,   79,   79,   79,   79,   79,   79,   79,
   79,   79,   79,   79,   79,   79,   79,   79,   79,   79,
   79
};

template<>
const uint32_t LangBase<LangPython>::Matrix_Chk[] =
{ 0,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,   13,   15,   16,   24,
   28,   24,   66,   41,   33,   15,   13,   16,   19,   19,
   28,   19,   33,   41,   19,   19,   21,   39,   21,   39,
   64,   21,   21,   42,   21,   62,   59,   21,   21,   58,
   55,   42,   55,   57,   60,   57,   60,   63,   56,   63,
   65,   52,   65,   67,   68,   67,   68,   65,   65,   51,
   67,   70,   71,   70,   71,   46,   45,   44,   70,   70,
   72,   43,   72,   34,   31,   29,   27,   72,   72,   73,

   26,   73,   23,   22,   17,   14,   73,   73,   75,    7,
   75,    6,    5,    4,    3,   75,   75,   76,    0,   76,
    0,    0,    0,    0,   76,   76,   77,    0,   77,    0,
    0,    0,    0,   77,   77,   78,    0,   78,    0,    0,
    0,    0,   78,   78,   80,   80,   80,   80,   80,   80,
   80,   80,   81,   81,    0,   81,   81,   81,   81,   81,
   82,   82,   82,   82,   82,   82,   82,   82,   83,   83,
    0,   83,   83,   83,   83,   83,   84,   84,   85,   85,
   85,   86,    0,    0,    0,    0,   86,   86,   87,   87,
   87,   87,   88,   88,   89,    0,    0,    0,    0,   89,

   89,   90,   90,   90,   90,   91,    0,   91,   91,   91,
   91,   91,   92,    0,    0,    0,    0,   92,   92,   93,
   93,   94,    0,   94,   94,   94,   94,   94,   95,    0,
   95,   95,   95,   95,   95,   96,   96,   97,    0,   97,
   97,   97,   97,   97,   79,   79,   79,   79,   79,   79,
   79,   79,   79,   79,   79,   79,   79,   79,   79,   79,
   79,   79,   79,   79,   79,   79,   79,   79,   79,   79,
   79
};

template<>
const struct HonestyChecker::Idf LangBase<LangPython>::Idf_PreprocessCommands[] = {
    {"define",		META('d')},
};

template<>
const struct HonestyChecker::Idf LangBase<LangPython>::Idf_Keywords[] = {
    {"and",          NORM('a')},
    {"as",           NORM('A')},
    {"assert",       CTRL('A')},
    {"async",        META('a')},
    {"await",        META('A')},
    {"break",        NORM('b')},
    {"class",        NORM('c')},
    {"continue",     NORM('C')},
    {"def",          NORM('d')},
    {"del",          NORM('D')},
    {"elif",         NORM('e')},
    {"else",         NORM('E')},
    {"except",       CTRL('E')},
    {"false",        NORM('f')},
    {"finally",      NORM('F')},
    {"for",          CTRL('F')},
    //{"from",         META('f')},
    {"global",       NORM('g')},
    {"if",           NORM('i')},
    //{"import",       NORM('I')},
    {"in",           CTRL('I')},
    {"is",           META('i')},
    {"lambda",       NORM('l')},
    {"none",         NORM('n')},
    {"nonlocal",     NORM('N')},
    {"not",          CTRL('N')},
    {"or",           NORM('o')},
    {"pass",         NORM('p')},
    {"raise",        NORM('r')},
    {"return",       NORM('R')},
    {"true",         NORM('t')},
    {"try",          NORM('T')},
    {"while",        NORM('w')},
    {"with",         NORM('W')},
    {"yield",        NORM('y')},
};

template<>
const std::set<Token> LangBase<LangPython>::Non_Initials = {
    NORM(')'),
    NORM(']'),
    NORM('}'),
    NORM(':'),
    NORM(','),
    NORM(';'),
};

template<>
const std::set<Token> LangBase<LangPython>::Non_Finals = {
    NORM('('),
    NORM('['),
    NORM('{'),
    NORM('a'),            /* and */
    NORM('A'),            /* as */
    CTRL('A'),            /* assert */
    META('a'),            /* async */
    META('A'),            /* await */
    NORM('b'),            /* break */
    NORM('c'),            /* class */
    NORM('C'),            /* continue */
    NORM('d'),            /* def */
    NORM('D'),            /* del */
    NORM('e'),            /* elif */
    NORM('E'),            /* else */
    CTRL('E'),            /* except */
    NORM('f'),            /* false */
    NORM('F'),            /* finally */
    CTRL('F'),            /* for */
    //META('f'),            /* from */
    NORM('g'),            /* global */
    NORM('i'),            /* if */
    //NORM('I'),            /* import */
    CTRL('I'),            /* in */
    META('i'),            /* is */
    NORM('l'),            /* lambda */
    NORM('n'),            /* none */
    NORM('N'),            /* nonlocal */
    CTRL('N'),            /* not */
    NORM('o'),            /* or */
    NORM('p'),            /* pass */
    NORM('r'),            /* raise */
    NORM('R'),            /* return */
    NORM('t'),            /* true */
    NORM('T'),            /* try */
    NORM('w'),            /* while */
    NORM('W'),            /* with */
    NORM('y'),            /* yield */
};

template<>
const std::set<Token> LangBase<LangPython>::Openers = {
    NORM('('),
    NORM('['),
    NORM('{'),
};

template<>
const std::set<Token> LangBase<LangPython>::Closers = {
    NORM(')'),
    NORM(']'),
    NORM('}'),
};


Lang* LangPython::instance = nullptr;

size_t LangPython::getLengthOfPreprocessCommandsList() {
    return 0;
}
size_t LangPython::getLengthOfKeywordsList() {
    return sizeof(LangPython::Idf_Keywords) / sizeof(HonestyChecker::Idf);
}

template<>
Tokenizer::DispatchingActionResult LangBase<LangPython>::dispatchActionForTokenizer(
    Tokenizer* tokenizer, int action
) {

#define StartState_INITIAL 0
#define StartState_Comment1 1
#define StartState_Comment2 2

	switch (action) {
	    case 1: {
		    tokenizer->setStartState(StartState_Comment1);
		    break;
	    }
	    case 2: {
		    tokenizer->setStartState(StartState_INITIAL);
		    break;
	    }
	    case 3: {
		    tokenizer->setStartState(StartState_Comment2);
		    break;
	    }
	    case 4: {
		    tokenizer->setStartState(StartState_INITIAL);
		    break;
	    }
	    /* rule 5 can match eol */
	    /* single-line comment */
	    case 5: {		
		    break;
	    }
	    case 6: {
		    tokenizer->recordToken(Token::STR);
		    break;
	    }
	    case 7: {
		    tokenizer->recordToken(Token::STR);
		    break;
	    }
	    /* ignore import lines */
	    case 8: {
		    break;
	    }
	    /* ignore import lines */
	    case 9: {
		    break;
	    }
	    /* identifier */
	    case 10: {
		    Token token = tokenizer->getTokenFromIdfList(tokenizer->_matched_text,
			    this->getKeywords(),
			    this->getLengthOfKeywordsList(),
			    Token::IDF);
		    if (token != Token::None) tokenizer->recordToken(token);
		    break;
	    }
	    /* numeral, passed as an identifier */
	    case 11: {
		    tokenizer->recordToken(Token::IDF);
		    break;
	    }
	    case 12: {
		    break;
	    }
	    case 13: {
		    break;
	    }
	    /* ignore layout */
	    case 14: {
		    break;
	    }
	    /* copy other text */
	    case 15: {
		    tokenizer->recordCharacter(*(tokenizer->_matched_text));
		    break;
	    }
	    case 16: {
		    break;
	    }
        case 18: {
            if (tokenizer->_matched_text_length <= 0) {
                return Tokenizer::DispatchingActionResult::Halt;
            }
            else {
                tokenizer->backToPreviousState();
                return Tokenizer::DispatchingActionResult::FindActionAgain;
            }
            break;
        }
	} /* end of action switch */
    return Tokenizer::DispatchingActionResult::Default;
}