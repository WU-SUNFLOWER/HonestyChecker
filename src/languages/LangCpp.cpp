#include "LangCpp.h"

using namespace HonestyChecker;

template<>
const uint32_t LangBase<LangCpp>::Magic_Number_1 = 94;
template<>
const uint32_t LangBase<LangCpp>::Magic_Number_2 = 363;

template<>
const uint32_t LangBase<LangCpp>::Matrix_Accept[] = {
    0,
    0,    0,    0,    0,   20,   18,   16,   15,   16,   17,
    17,   17,   17,   11,   11,   14,   11,   13,   17,    2,
    2,    4,    2,    2,    2,    2,    3,    2,    2,    2,
    2,    2,    2,    2,    0,    7,    0,    0,    0,    1,
    0,   11,   11,    0,   12,   11,   13,   11,    0,   10,
    10,    2,    2,    2,    2,    2,    2,    5,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    8,
    0,    6,   10,   10,    2,    2,    2,    2,   10,    2,
    10,    2,   10,    2,   10,    2,    9,    2,    9,    9,
    2,    2,    0
};

template<>
const uint32_t LangBase<LangCpp>::Matrix_Ec[] = {
    0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    2,    2,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    4,    5,    6,    7,    5,    5,    5,    8,    9,
        5,   10,    5,    5,    5,    5,   11,   12,   13,   13,
       13,   13,   13,   13,   13,   13,   13,    5,   14,    5,
        5,    5,    5,    5,   15,   15,   15,   15,   15,   15,
       16,   16,   16,   16,   16,   17,   16,   16,   16,   16,
       16,   16,   16,   16,   16,   16,   16,   16,   16,   16,
        5,   18,    5,    5,   16,    5,   15,   15,   19,   20,

       21,   15,   16,   16,   22,   16,   16,   23,   16,   24,
       16,   16,   16,   16,   16,   16,   25,   16,   16,   26,
       16,   16,    5,    5,    5,    5,    1,    1,    1,    1,
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
const uint32_t LangBase<LangCpp>::Matrix_Meta[] = {
        0,
        1,    2,    3,    2,    1,    1,    1,    4,    5,    6,
        1,    7,    7,    1,    8,    9,    8,    1,    8,    8,
        8,    9,    8,    9,    9,    8
};

template<>
const uint32_t LangBase<LangCpp>::Matrix_Base[] = {
       0,
        0,  310,   26,  301,  302,  363,  363,  363,  363,  363,
       47,  281,   44,   40,   41,  363,   59,  285,   84,    0,
        0,  363,    0,    0,   81,   51,  282,   79,   95,  266,
        0,  121,  136,  159,   86,  363,    0,   52,  283,  363,
      287,    0,  363,   39,  363,    0,  276,  267,   91,    0,
      251,    0,   91,    0,  256,  144,  230,  363,   93,  188,
        0,   94,    0,    0,    0,    0,    0,  185,  171,  363,
      185,  363,    0,  150,    0,   95,    0,  139,  127,  108,
       99,   94,   82,   80,   73,   56,  211,  237,    0,    0,
       63,    0,  363,  263,  272,  275,  279,  287,  296,  305,

      314,  323,  326,  335,  344,  353
};

template<>
const uint32_t LangBase<LangCpp>::Matrix_Def[] = {
       0,
       93,    1,   93,    3,   93,   93,   93,   93,   93,   93,
       94,   95,   93,   96,   96,   93,   93,   97,   98,   99,
       99,   93,   99,   99,  100,  101,   93,   99,   99,   29,
       99,   93,   32,   93,   94,   93,   94,   95,   95,   93,
      102,   15,   93,   15,   93,   17,   97,   97,   98,  103,
      103,   99,  100,   99,  100,  101,  101,   93,  104,   29,
       99,   29,   99,   32,   33,   33,   34,   93,   68,   93,
      102,   93,  103,  103,   99,  104,   68,   68,  103,   68,
      103,   68,  103,   68,  103,   68,   93,   93,  105,   87,
      106,   88,    0,   93,   93,   93,   93,   93,   93,   93,

       93,   93,   93,   93,   93,   93
};

template<>
const uint32_t LangBase<LangCpp>::Matrix_Nxt[] = {
       0,
        6,    7,    8,    9,   10,   11,   10,   12,   10,   10,
       13,   14,   15,   16,   17,   18,   18,   10,   17,   17,
       17,   18,   18,   18,   18,   18,   20,   21,   22,   23,
       24,   25,   24,   26,   24,   27,   28,   29,   30,   31,
       32,   33,   33,   24,   32,   32,   32,   33,   33,   33,
       33,   33,   36,   40,   41,   93,   43,   43,   52,   70,
       38,   93,   43,   43,   37,   44,   93,   45,   57,   39,
       46,   46,   89,   46,   47,   48,   88,   46,   46,   46,
       47,   48,   47,   47,   47,   49,   54,   49,   40,   59,
       35,   36,   49,   87,   49,   72,   54,   72,   55,   86,

       35,   85,   71,   37,   71,   51,   60,   60,   55,   60,
       52,   61,   51,   60,   60,   60,   52,   61,   84,   52,
       62,   52,   52,   83,   52,   52,   52,   52,   52,   63,
       82,   52,   64,   64,   52,   64,   65,   66,   52,   64,
       64,   64,   65,   66,   65,   65,   65,   65,   65,   81,
       65,   75,   65,   38,   65,   65,   65,   80,   65,   52,
       67,   57,   67,   52,   52,   52,   52,   52,   79,   52,
       52,   52,   52,   68,   68,   68,   52,   68,   68,   68,
       69,   68,   68,   68,   68,   52,   52,   72,   52,   52,
       52,   52,   52,   52,   78,   52,   77,   77,   52,   77,

       77,   77,   52,   77,   77,   77,   77,   77,   77,   77,
       77,   89,   89,   52,   89,   89,   89,   89,   89,   89,
       89,   89,   90,   90,   89,   90,   90,   90,   89,   90,
       90,   90,   90,   90,   90,   90,   90,   91,   91,   38,
       91,   91,   91,   91,   91,   91,   89,   91,   92,   92,
       91,   92,   92,   92,   91,   92,   92,   92,   92,   92,
       92,   92,   92,   35,   35,   35,   35,   35,   35,   35,
       35,   35,   38,   38,   74,   45,   38,   38,   38,   38,
       38,   42,   42,   47,   45,   47,   47,   47,   50,   72,
       38,   52,   58,   45,   50,   50,   52,   52,   39,   52,

       52,   93,   52,   52,   52,   53,   53,   34,   53,   53,
       53,   53,   53,   53,   56,   56,   19,   56,   56,   56,
       56,   56,   56,   71,   71,   71,   71,   71,   71,   71,
       71,   71,   73,   73,   73,   76,   76,   76,   76,   76,
       76,   76,   76,   76,   89,   89,   93,   89,   89,   89,
       89,   89,   89,   91,   91,   93,   91,   91,   91,   91,
       91,   91,    5,   93,   93,   93,   93,   93,   93,   93,
       93,   93,   93,   93,   93,   93,   93,   93,   93,   93,
       93,   93,   93,   93,   93,   93,   93,   93,   93
};

template<>
const uint32_t LangBase<LangCpp>::Matrix_Chk[] = {
       0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    3,    3,    3,    3,
        3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
        3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
        3,    3,   11,   13,   13,   44,   14,   15,   26,   38,
       26,   44,   14,   15,   11,   14,   15,   17,   26,   38,
       17,   17,   91,   17,   17,   17,   86,   17,   17,   17,
       17,   17,   17,   17,   17,   19,   25,   19,   28,   28,
       25,   35,   49,   85,   49,   59,   53,   76,   25,   84,

       53,   83,   59,   35,   76,   19,   29,   29,   53,   29,
       62,   29,   49,   29,   29,   29,   62,   29,   82,   62,
       29,   32,   32,   81,   32,   32,   32,   32,   32,   32,
       80,   32,   32,   32,   32,   32,   32,   32,   32,   32,
       32,   32,   32,   32,   32,   32,   32,   33,   33,   79,
       33,   56,   33,   56,   33,   33,   33,   78,   33,   34,
       34,   56,   34,   34,   34,   34,   34,   34,   74,   34,
       34,   34,   34,   34,   34,   34,   34,   34,   34,   34,
       34,   34,   34,   34,   34,   68,   68,   71,   68,   68,
       68,   68,   68,   68,   69,   68,   68,   68,   68,   68,

       68,   68,   68,   68,   68,   68,   68,   68,   68,   68,
       68,   87,   87,   60,   87,   87,   87,   87,   87,   87,
       87,   87,   87,   87,   87,   87,   87,   87,   87,   87,
       87,   87,   87,   87,   87,   87,   87,   88,   88,   57,
       88,   88,   88,   88,   88,   88,   88,   88,   88,   88,
       88,   88,   88,   88,   88,   88,   88,   88,   88,   88,
       88,   88,   88,   94,   94,   55,   94,   94,   94,   94,
       94,   94,   95,   95,   51,   48,   95,   95,   95,   95,
       95,   96,   96,   97,   47,   97,   97,   97,   98,   41,
       39,   30,   27,   18,   98,   98,   99,   99,   12,   99,

       99,    5,   99,   99,   99,  100,  100,    4,  100,  100,
      100,  100,  100,  100,  101,  101,    2,  101,  101,  101,
      101,  101,  101,  102,  102,  102,  102,  102,  102,  102,
      102,  102,  103,  103,  103,  104,  104,  104,  104,  104,
      104,  104,  104,  104,  105,  105,    0,  105,  105,  105,
      105,  105,  105,  106,  106,    0,  106,  106,  106,  106,
      106,  106,   93,   93,   93,   93,   93,   93,   93,   93,
       93,   93,   93,   93,   93,   93,   93,   93,   93,   93,
       93,   93,   93,   93,   93,   93,   93,   93,   93
};

template<>
const struct HonestyChecker::Idf LangBase<LangCpp>::Idf_PreprocessCommands[] = {
    {"define",		META('d')},
    {"elif",		META('e')},
    {"else",		META('E')},
    {"endif",		META('n')},
    {"error",		META('r')},
    {"if",			META('i')},
    {"ifdef",		META('I')},
    {"ifndef",		META('x')},
    {"include",		MTCT('I')},
    {"line",		META('l')},
    {"pragma",		META('p')},
    {"undef",		META('u')}
};

template<>
const struct HonestyChecker::Idf LangBase<LangCpp>::Idf_Keywords[] = {
    {"and",			NORM('a')},
    {"and_eq",		NORM('A')},
    {"asm",			CTRL('A')},
    {"auto",		META('a')},
    {"bitand",		NORM('b')},
    {"bitor",		NORM('B')},
    {"bool",		CTRL('B')},
    {"break",		META('b')},
    {"case",		NORM('c')},
    {"char",		NORM('C')},
    {"class",		CTRL('C')},
    {"const",		META('c')},
    {"const_cast",		META('C')},
    {"continue",		MTCT('C')},
    {"default",		NORM('d')},
    {"delete",		NORM('D')},
    {"do",			CTRL('D')},
    {"double",		META('D')},
    {"dynamic_cast",	MTCT('D')},
    {"else",		NORM('e')},
    {"enum",		NORM('E')},
    {"explicit",CTRL('E')},
    {"extern",		MTCT('E')},
    {"false",		NORM('f')},
    {"float",		NORM('F')},
    {"for",			CTRL('F')},
    {"friend",		META('f')},
    {"goto",		NORM('g')},
    {"if",			NORM('i')},
    {"inline",		NORM('I')},
    {"int",			CTRL('I')},
    {"long",		NORM('l')},
    {"mutable",		NORM('m')},
    {"namespace",		NORM('n')},
    {"new",			NORM('N')},
    {"not",			CTRL('N')},
    {"not_eq",		META('N')},
    {"operator",		NORM('o')},
    {"or",			NORM('O')},
    {"or_eq",		CTRL('O')},
    {"private",		NORM('p')},
    {"protected",		NORM('P')},
    {"public",		CTRL('P')},
    {"register",		HonestyChecker::Token::None},
    {"reinterpret_cast",	NORM('r')},
    {"return",		NORM('R')},
    {"short",		NORM('s')},
    {"signed",		NORM('S')},
    {"sizeof",		CTRL('S')},
    {"static",		META('s')},
    {"static_cast",		META('S')},
    {"struct",		MTCT('S')},
    {"switch",		META('w')},
    {"template",		NORM('t')},
    {"this",		NORM('T')},
    {"throw",		CTRL('T')},
    {"true",		META('t')},
    {"try",			META('T')},
    {"typedef",		MTCT('T')},
    {"typeid",		NORM('y')},
    {"typename",		NORM('z')},
    {"union",		NORM('u')},
    {"unsigned",		NORM('U')},
    {"using",		CTRL('U')},
    {"virtual",		NORM('v')},
    {"void",		NORM('V')},
    {"while",		NORM('w')},
    {"xor",			NORM('x')},
    {"xor_eq",		NORM('X')}
};

template<>
const std::set<Token> LangBase<LangCpp>::Non_Initials = {
    NORM(')'),
    NORM('}'),
    NORM(';'),
};

template<>
const std::set<Token> LangBase<LangCpp>::Non_Finals = {
    Token::IDF,			/* identifier */
    NORM('{'),
    NORM('('),
    NORM('a'),		/* and */
    NORM('A'),		/* and_eq */
    CTRL('A'),		/* asm */
    META('a'),		/* auto */
    NORM('b'),		/* bitand */
    NORM('B'),		/* bitor */
    CTRL('B'),		/* bool */
    META('b'),		/* break */
    NORM('c'),		/* case */
    NORM('C'),		/* char */
    CTRL('C'),		/* class */
    META('c'),		/* const */
    META('C'),		/* const_cast */
    MTCT('C'),		/* continue */
    NORM('d'),		/* default */
    NORM('D'),		/* delete */
    CTRL('D'),		/* do */
    META('D'),		/* double */
    MTCT('D'),		/* dynamic_cast */
    NORM('e'),		/* else */
    NORM('E'),		/* enum */
    CTRL('E'),		/* explicit */
    MTCT('E'),		/* extern */
    NORM('F'),		/* float */
    CTRL('F'),		/* for */
    META('f'),		/* friend */
    NORM('g'),		/* goto */
    NORM('i'),		/* if */
    NORM('I'),		/* inline */
    CTRL('I'),		/* int */
    NORM('l'),		/* long */
    NORM('m'),		/* mutable */
    NORM('n'),		/* namespace */
    NORM('N'),		/* new */
    CTRL('N'),		/* not */
    META('N'),		/* not_eq */
    NORM('o'),		/* operator */
    NORM('O'),		/* or */
    CTRL('O'),		/* or_eq */
    NORM('p'),		/* private */
    NORM('P'),		/* protected */
    CTRL('P'),		/* public */
    NORM('r'),		/* reinterpret_cast */
    NORM('R'),		/* return */
    NORM('s'),		/* short */
    NORM('S'),		/* signed */
    CTRL('S'),		/* sizeof */
    META('s'),		/* static */
    META('S'),		/* static_cast */
    MTCT('S'),		/* struct */
    META('w'),		/* switch */
    NORM('t'),		/* template */
    CTRL('T'),		/* throw */
    META('T'),		/* try */
    MTCT('T'),		/* typedef */
    NORM('y'),		/* typeid */
    NORM('z'),		/* typename */
    NORM('u'),		/* union */
    NORM('U'),		/* unsigned */
    CTRL('U'),		/* using */
    NORM('v'),		/* virtual */
    NORM('V'),		/* volatile */
    CTRL('V'),		/* void */
    NORM('w'),		/* while */
    NORM('x'),		/* xor */
    NORM('X'),		/* xor_eq */
};

template<>
const std::set<Token> LangBase<LangCpp>::Openers = {
    NORM('{'),
    NORM('('),
    NORM('['),
};

template<>
const std::set<Token> LangBase<LangCpp>::Closers = {
    NORM('}'),
    NORM(')'),
    NORM(']'),
};

Lang* LangCpp::instance = nullptr;

size_t LangCpp::getLengthOfPreprocessCommandsList() {
    return sizeof(LangCpp::Idf_PreprocessCommands) / sizeof(HonestyChecker::Idf);
}
size_t LangCpp::getLengthOfKeywordsList() {
    return sizeof(LangCpp::Idf_Keywords) / sizeof(HonestyChecker::Idf);
}

template<>
Tokenizer::DispatchingActionResult LangBase<LangCpp>::dispatchActionForTokenizer(
    Tokenizer* tokenizer, int action
) {

#define StartState_Initial 0
#define StartState_Comment 1

    switch (action) {
        /* start comment */
        case 1: {
            tokenizer->setStartState(StartState_Comment);
            break;
        }
        /* safe comment chunk */
        case 2: {
            break;
        }
        /* unsafe char, read one by one */
        case 3: {
            break;
        }
        /* match eol, to break up long comments */
        case 4: {
            tokenizer->recordEOL();
            break;
        }
        case 5: {
            tokenizer->setStartState(StartState_Initial);
            break;
        }
        /* single-line comment */
        case 6: {
            tokenizer->recordEOL();
            break;
        }
        /* strings */
        case 7: {
            tokenizer->recordToken(Token::STR);
            break;
        }
        /* characters */
        case 8: {
            tokenizer->recordCharacter('\'');
            break;
        }
        /* ignore #include lines */
        case 9: {
            break;
        }
        /* a preprocessor line */
        case 10: {
            char* idf = tokenizer->_matched_text + 1;
            /* skip layout in front of preprocessor identifier */
            while (*idf == ' ' || *idf == '\t') idf++;
            Token token = tokenizer->getTokenFromIdfList(idf,
                this->getPreprocessCommands(),
                this->getLengthOfPreprocessCommandsList(),
                NORM('#'));
            tokenizer->recordToken(token);
            break;
        }
        /* numeral, passed as an identifier */
        case 11: {
            tokenizer->recordToken(Token::IDF);
            break;
        }
        /* identifier in front of ( */
        case 12: {
            // undo effects of setting up yytext
            //_text[_currentTextPos] = _backup_char;
            --tokenizer->_currentTextPos;
            // set up yytext again
            tokenizer->setupMatchedText();

            Token token = tokenizer->getTokenFromIdfList(tokenizer->_matched_text,
                this->getKeywords(),
                this->getLengthOfKeywordsList(),
                Token::IDF);
            if (token != Token::None) tokenizer->recordToken(token);
            break;
        }
        /* identifier */
        case 13: {
            Token token = tokenizer->getTokenFromIdfList(tokenizer->_matched_text,
                this->getKeywords(),
                this->getLengthOfKeywordsList(),
                Token::IDF);
            if (token != Token::None) tokenizer->recordToken(token);
            break;
        }
        /* semicolon, conditionally ignored */
        case 14: {
            break;
        }
        /* count newlines */
        case 15: {
            tokenizer->recordEOL();
            break;
        }
        /* ignore layout */
        case 16: {
            break;
        }
        /* copy other text */
        case 17: {
            tokenizer->recordCharacter(*(tokenizer->_matched_text));
            break;
        }
        /* count non-ASCII chars */
        case 18: {
            break;
        }
        case 20: {
            if (tokenizer->_matched_text_length <= 0) {
                return Tokenizer::DispatchingActionResult::Halt;
            }
            else {
                tokenizer->backToPreviousState();
                return Tokenizer::DispatchingActionResult::FindActionAgain;
            }
            break;
        }
    }
    return Tokenizer::DispatchingActionResult::Default;
}