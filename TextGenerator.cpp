// Copyright 2015 Kim Douglas
#include <time.h>
#include <stdlib.h>
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include "MarkovModel.hpp"

const int USAGE = 1;
std::string usage = "usage: ./TextGenerator <order_k> <kgram_length> <input>";

int main(int argc, char* argv[]) {
    if (argc == USAGE) throw std::runtime_error(usage);

    int k = atoi(argv[1]);
    int t = atoi(argv[2]);
    std::string input, kgram;
    std::cin >> input;

    MarkovModel mm(input, k);
    // MarkovModel mm("gagggagaggcgagaaa", 0);
    std::cout << mm << std::endl;

    srand(time(NULL));
    kgram = input.substr(0, k);
    std::string generated_text = mm.gen(kgram, t);

    std::cout << "Original string:  " << input << std::endl;
    std::cout << "Generated string: " << generated_text << std::endl;
    std::cout << std::endl;

    return 0;
}
