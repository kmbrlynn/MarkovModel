#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "MarkovModel.hpp"

int main(int argc, char* argv[]) {
   
  //  MarkovModel mm("abcdefgh", 3);
 
    srand(time(NULL));

    MarkovModel mm("gagggagaggcgagaaa", 1);
    std::cout << mm << std::endl;

//    char randchar = mm.randk("a");
  //  std::cout << "rand char = " << randchar << std::endl;

	return 0;
}
