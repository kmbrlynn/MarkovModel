#include <iostream>
#include "MarkovModel.hpp"

int main(int argc, char* argv[]) {
   
    MarkovModel mm("abcdefgh", 3);
 //   MarkovModel mm("gagggagagggcgagaaa", 2);
    std::cout << mm;

	return 0;
}
