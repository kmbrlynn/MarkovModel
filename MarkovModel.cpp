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
    int kgram_back, kplus_back;

    // Parse the alphabet out of the string of text
    std::sort(_alpha.begin(), _alpha.end());
    _alpha.erase(std::unique(_alpha.begin(), _alpha.end()), _alpha.end());

    // build k-grams and k-plus-one-grams
    for (unsigned int i = 0; i < text.length(); i++) {
        std::string kgram_str, kplus_str, wrap_str;
        int wrap_back;
        
        kgram_back = i+k;
        kplus_back = kgram_back + 1;
       
        // Get current kgram: wraparound + append, if necessary
        // then put it in the map, or tally existing one
        if (kgram_back >= text.length()) { 
            wrap_back = kgram_back - text.length();
            wrap_str = text.substr(0, wrap_back);
            kgram_str = text.substr(i, text.length()-1);
            kgram_str.append(wrap_str); 
        } else kgram_str = text.substr(i, k);       
        std::cout << "got kgram: " << kgram_str << std::endl;
        
        std::map<std::string, int>::iterator kg_it = _kgrams.find(kgram_str);
        if (kg_it != _kgrams.end()) {
            kg_it-> second += 1;
            std::cout << "tallied kgram: " << kgram_str << std::endl;
        } else {
            _kgrams[kgram_str] = 1;
            std::cout << "created kgram " << kgram_str << std::endl; 
        }

        // Get current kplus-one-gram: based on current kgram
        // then put it in the map, or tally existing one
        if (kplus_back == text.length()) kplus_back = text.at(0);   
        kplus_str = kgram_str + text.at(kplus_back);
        std::cout << "got kplus: " << kplus_str << std::endl;

        std::map<std::string, int>::iterator kp_it = _kgrams.find(kplus_str);
        if (kp_it != _kgrams.end()) {
            kp_it-> second += 1;
            std::cout << "tallied kplus: " << kgram_str << std::endl;
        } else {
            _kgrams[kplus_str] = 1;
            std::cout << "created kplus " << kplus_str << std::endl;
        }
        std::cout << std::endl;
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






















