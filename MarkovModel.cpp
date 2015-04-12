// Copyright Kim Doglas 2015
#include <map>
#include <string>
#include "MarkovModel.hpp"

// ============================================================ con/destructors
MarkovModel::MarkovModel(std::string text, int k) : 
                                    _alphabet(text), _order(k) {
                  
    std::string kgram_str, wrap_str;
    int kgram_back, wrap_back;

    for (unsigned int i = 0; i < _alphabet.length(); i++) {
        kgram_back = i+k-1;

        // Get the current kgram
        if (kgram_back >= _alphabet.length()) { 
            // grab the wraparound chunk
            wrap_back = kgram_back - _alphabet.length();
            wrap_str = _alphabet.substr(0, wrap_back);
            // append to the truncated kgram
            kgram_str = _alphabet.substr(i, _alphabet.length()-1);
            kgram_str.append(wrap_str);
        } else { 
            kgram_str = _alphabet.substr(i, kgram_back);
        }        

        // Put it in the map, or tally the existing one
        std::map<std::string, int>::iterator it = _kgrams.find(kgram_str);
        if (it != _kgrams.end())
            it-> second += 1;
        else
            _kgrams[kgram_str] = 1;
    }
}

MarkovModel::~MarkovModel() {
}

// ================================================================== accessors
int MarkovModel::order() {
    return _order;
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
    std::map<std::string, char>::iterator it;        

}






















