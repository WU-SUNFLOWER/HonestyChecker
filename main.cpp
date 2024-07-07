#include <iostream>
#include <fstream>
#include <sstream>
#include "Tokenizer.h"
#include "Text.h"
#include "Comparer.h"

void readText(std::string filename, std::vector<Token>& vec, std::vector<Text>& texts) {
    std::stringstream stream;
    std::ifstream file(filename);
    stream << file.rdbuf();
    file.close();
    std::string str = stream.str();
    const char* code = str.c_str();

    Tokenizer tokenizer(code, strlen(code), vec, 0);
    size_t begin = vec.size();
    size_t length = tokenizer.run();
    Text text(vec, begin, begin + length);

    texts.push_back(text);

}

int main() {
    
    std::vector<Token> vec = {Token::None};
    std::vector<Text> texts;

    readText("test_case/a.txt", vec, texts);
    readText("test_case/b.txt", vec, texts);
    readText("test_case/c.txt", vec, texts);

    Comparer comparer(vec, texts);
    printf("%lf", comparer.run());

    /*
    FILE* outfile = fopen("test_case/token.txt", "w");

    int cnt = 0;
    for (auto& tk : vec) {
        fprintf(outfile, "%d ", cnt);
        tk.print(outfile);
        fprintf(outfile, "\n");
        ++cnt;
    }    
    */





}