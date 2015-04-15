// Copyright 2015 Kim Douglas
#include <time.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "MarkovModel.hpp"

int main(int argc, char* argv[]) {
    int k = atoi(argv[1]);
    int t = atoi(argv[2]);  
    std::string input, kgram;
    std::cin >> input;

    MarkovModel mm(input, k);
//    std::cout << mm << std::endl;

    srand(time(NULL));
    kgram = input.substr(0, k);
    std::string generated_text = mm.gen(kgram, t);
   
    std::cout << "Original:  " << input << std::endl;
    std::cout << "Generated: " << generated_text << std::endl;

    return 0;
}
