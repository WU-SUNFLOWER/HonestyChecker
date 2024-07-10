#include <iostream>
#include <fstream>
#include <sstream>
#include "LangCpp.h"
#include "LangPython.h"
#include "Tokenizer.h"
#include "Text.h"
#include "Comparer.h"
#include <cstring>

using namespace HonestyChecker;

void readText(
    std::string filename, Tokenizer& tokenizer, std::vector<Text>& texts
) {
    std::stringstream stream;
    std::ifstream file(filename);

    if (!file) {
        printf("Can't open %s\n", filename.c_str());
        exit(-1);
    }

    stream << file.rdbuf();
    file.close();
    std::string str = stream.str();
    const char* code = str.c_str();

    tokenizer.initialize(code);

    size_t begin = tokenizer.vector().size();
    size_t end = begin + tokenizer.run();
    
    texts.push_back({tokenizer.vector(), begin, end});

}

int main() {
    
    const char* langname = "Python3";
    std::vector<Token> vec = {Token::None};
    std::vector<Text> texts;

    Lang* lang = nullptr;

    if (strcmp(langname, "C++") == 0) {
        lang = LangCpp::getInstance();
    }
    else if (strcmp(langname, "Python3") == 0) {
        lang = LangPython::getInstance();
    }
    else {
        printf("Unknown language '%s'.", langname);
        exit(-1);
    }

    Tokenizer tokenizer(vec, lang);
    readText("test_case/2_a.txt", tokenizer, texts);
    readText("test_case/2_b.txt", tokenizer, texts);

    Comparer comparer(vec, texts, lang);
    printf("%lf", comparer.run());

}