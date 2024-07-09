#include <iostream>
#include <fstream>
#include <sstream>
#include "LangCpp.h"
#include "LangPython.h"
#include "Tokenizer.h"
#include "Text.h"
#include "Comparer.h"

using namespace HonestyChecker;

void readText(std::string filename, std::vector<Token>& vec, std::vector<Text>& texts, Lang* lang) {
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

    Tokenizer tokenizer(code, strlen(code), vec, lang);
    size_t begin = vec.size();
    size_t length = tokenizer.run();
    tokenizer.printVector(begin, begin+length);

    Text text(vec, begin, begin + length);

    texts.push_back(text);

}

int main() {
    
    const char* langname = "Python3";
    std::vector<Token> vec = {Token::None};
    std::vector<Text> texts;

    Lang* lang1 = nullptr;

    if (strcmp(langname, "C++") == 0) {
        lang1 = LangCpp::getInstance();
    }
    else if (strcmp(langname, "Python3") == 0) {
        lang1 = LangPython::getInstance();
    }
    else {
        printf("Unknown language '%s'.", langname);
        exit(-1);
    }

    readText("../test_case/2_a.txt", vec, texts, lang1);
    readText("../test_case/2_b.txt", vec, texts, lang1);
    //readText("../test_case/2_c.txt", vec, texts, lang1);

    Comparer comparer(vec, texts, lang1);
    printf("%lf", comparer.run());

}