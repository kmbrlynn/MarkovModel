// Copyright Kim Doglas 2015
#include <map>
#include <string>
#include "MarkovModel.hpp"

// ============================================================ con/destructors
MarkovModel::MarkovModel(std::string text, int k) {




}

MarkovModel::~MarkovModel() {
}

// ================================================================== accessors
int MarkovModel::order() {

}

int MarkovModel::freq(std::string kgram) {

}

int MarkovModel::freq(std::string kgram, char c) {

}

char MarkovModel::randk(std::string kgram) {

}

std::string MarkovModel::gen(std::string kgram, int t) {

}

// ==================================================================== friends
std::ostream& operator << (std::ostream& os, MarkovModel& mm) {


}


