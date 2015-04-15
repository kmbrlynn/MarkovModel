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
  // MarkovModel mm("gagggagaggcgagaaa", 0);
    std::cout << mm << std::endl;

    srand(time(NULL));
    kgram = input.substr(0, t);
    std::string generated_text = mm.gen(kgram, t);
   
    std::cout << "Original string:  " << input << std::endl;
    std::cout << "Generated string: " << generated_text << std::endl;
    std::cout << std::endl;

    return 0;
}
