#include <iostream>
#include <fstream>
#include <sstream>
#include "tokenizer.h"

int main() {
    
    std::stringstream stream;
    std::ifstream file("test_case/b.txt");
    stream << file.rdbuf();
    file.close();
    std::string str = stream.str();
    const char* code = str.c_str();

    std::cout << str << std::endl;

    std::vector<Token> target;
    Tokenizer tokenizer(code, strlen(code), target, 0);
    tokenizer.run();

    std::cout << target.size() << std::endl;

    for (auto& token : target) {
        token.print();
    }

}