// Copyright Kim Douglas 2015
#include <map>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <algorithm>
#include "MarkovModel.hpp"

std::string freq_err = "freq(string, [int]): kgram length musn't exceed order";

// ============================================================ con/destructors
MarkovModel::MarkovModel(std::string text, int k) : _order(k), _alpha(text) { 
    std::string kgram_str, wrap_str;
    int kgram_back, wrap_back;

    // Parse the alphabet out of the string of text
    std::sort(_alpha.begin(), _alpha.end());
    _alpha.erase(std::unique(_alpha.begin(), _alpha.end()), _alpha.end());

    // assign each unique _alpha character a 'tally' variable
    // so, maintain 3 for this example - a, g, c
    // check against each tally var when you have a kgram collision
    // store in member vector?


    for (unsigned int i = 0; i < text.length(); i++) {
        kgram_back = i+k;

        // Get the current kgram
        if (kgram_back >= text.length()) { 
            // grab the wraparound chunk
            wrap_back = kgram_back - text.length();
            wrap_str = text.substr(0, wrap_back);
            // append to the truncated kgram
            kgram_str = text.substr(i, text.length()-1);
            kgram_str.append(wrap_str);
        } else { 
            kgram_str = text.substr(i, k);
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
    if (kgram.length() != _order) throw std::runtime_error(freq_err);
    std::map<std::string, int>::iterator it = _kgrams.find(kgram);
    if (it != _kgrams.end())
        return it-> second;
    else
       return 0;
}

int MarkovModel::freq(std::string kgram, char c) {
    if (kgram.length() != _order) throw std::runtime_error(freq_err);
}

char MarkovModel::randk(std::string kgram) {

}

std::string MarkovModel::gen(std::string kgram, int t) {

}

// ==================================================================== friends
std::ostream& operator << (std::ostream& os, MarkovModel& mm) {
    std::map<std::string, int>::iterator it;
    for (it = mm._kgrams.begin(); it != mm._kgrams.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}






















