%{

#include	"global.h"
#include	"options.h"
#include	"token.h"
#include	"properties.h"
#include	"idf.h"
#include	"lex.h"
#include	"lang.h"

/* General language front end data */
Token lex_token;
size_t lex_nl_cnt;
size_t lex_tk_cnt;
size_t lex_non_ASCII_cnt;

/* Language-dependent data */

/* Data for module idf */

static const struct idf reserved[] = {
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

static const Token Non_Finals[] = {
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
	No_Token
};

static const Token Non_Initials[] = {
	NORM(')'),
	NORM(']'),
	NORM('}'),
	NORM(':'),
	NORM(','),
	NORM(';'),
	No_Token
};

static const Token Openers[] = {
	NORM('('),
	NORM('['),
	NORM('{'),
	No_Token
};

static const Token Closers[] = {
	NORM(')'),
	NORM(']'),
	NORM('}'),
	No_Token
};

/* Special treatment of identifiers */

static Token
idf2token(int hashing) {
	Token tk;

	tk = Idf_In_List(yytext, reserved, sizeof reserved, IDF);
	if (Token_EQ(tk, IDF) && hashing) {
		/* return a one-Token hash code */
		tk = Idf_Hashed(yytext);
	}
	return tk;
}

void
Init_Language(void) {
	Subject = "Python programs";
	Init_Language_Properties(Non_Finals, Non_Initials, Openers, Closers);
}

%}

%option	noyywrap

%Start	Comment1
%Start	Comment2

Layout		([ \t\r\f])
ASCII95		([\040-\176])

AnyQuoted	(\\.)
PrefixOfStr ([bfur])
StrChar		([^\"\n\\]|{AnyQuoted})
ChrChar		([^\'\n\\]|{AnyQuoted})

StartComment1	(\"\"\")
EndComment1	(\"\"\")

StartComment2	(\'\'\')
EndComment2	(\'\'\')

SingleLineCom	("#".*)

HexDigit	([0-9a-fA-F])
Idf		([A-Za-z_][A-Za-z0-9_]*)
EnhancedIdf     ({Idf}(\.{Idf})*)

FromCommand ("from"{Layout}+{EnhancedIdf})
ImportCommand ("import"{Layout}+{EnhancedIdf}({Layout}*\,{Layout}*{EnhancedIdf})*)

%%

<INITIAL>{StartComment1}	{
		BEGIN Comment1;
	}

<Comment1>{EndComment1}	{		/* end-of-comment */
		BEGIN INITIAL;
	}

<INITIAL>{StartComment2}	{
		BEGIN Comment2;
	}

<Comment2>{EndComment2}	{		/* end-of-comment */
		BEGIN INITIAL;
	}

<INITIAL>{SingleLineCom}"\n"	{		/* single-line comment */
		
	}
    
<INITIAL>{PrefixOfStr}?\"{StrChar}*\"	{
		return_ch(STR);
	}

<INITIAL>{PrefixOfStr}?\'{ChrChar}*\'	{
		return_ch(STR);
	}
    
<INITIAL>{FromCommand}	{}		/* ignore import lines */
<INITIAL>{ImportCommand}	{}		/* ignore import lines */

<INITIAL>{Idf} {				/* identifier */
    Token tk;
	tk = idf2token(0 /* no hashing */);
	if (!Token_EQ(tk, No_Token)) return_tk(tk);
}

<INITIAL>(0x|0b)?{HexDigit}+	{      	/* numeral, passed as an identifier */
    return_tk(IDF);
}


<INITIAL>\;	{
    
}

<INITIAL>\n	{
    
}

<INITIAL>{Layout}	{			/* ignore layout */
}

<INITIAL>{ASCII95} {			/* copy other text */
    return_ch(yytext[0]);
}

<INITIAL>. {				/* count non-ASCII chars */
    
}

%%

/* More language-dependent code */

void
yystart(void) {
	BEGIN INITIAL;
}