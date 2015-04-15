#include <iostream>
#include "MarkovModel.hpp"

int main(int argc, char* argv[]) {
   
  //  MarkovModel mm("abcdefgh", 3);
 
    MarkovModel mm("gagggagaggcgagaaa", 0);
    std::cout << mm << std::endl;

  
	return 0;
}
