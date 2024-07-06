#include <iostream>
#include "tokenizer.h"

int main() {
    char text[] = "int a = 0, b = 2;\0";
    std::vector<Token> target;
    Tokenizer tokenizer(text, strlen(text), target, 0);
    tokenizer.run();
    std::cout << target.size();
}