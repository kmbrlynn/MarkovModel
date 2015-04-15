// Copyright 2015 Kim Douglas
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "MarkovModel.hpp"

int main(int argc, char* argv[]) {
    srand(time(NULL));

    MarkovModel mm("gagggagaggcgagaaa", 1);
    std::cout << mm << std::endl;

    return 0;
}
