// Copyright Kim Douglas 2015
#include <map>
#include <vector>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <algorithm>
#include "MarkovModel.hpp"

std::string freq_err = "freq(string, [int]): kgram length musn't exceed order";
std::string con_err = "constructor: test must be at least as long as order";

// ============================================================ con/destructors
MarkovModel::MarkovModel(std::string text, int k) : _order(k), _alpha(text) { 
    int kgram_back, kplus_back;
    
    _text = text;
    if (_order > _text.length()) throw std::runtime_error(con_err);

    // Parse the alphabet out of the string of text
    std::sort(_alpha.begin(), _alpha.end());
    _alpha.erase(std::unique(_alpha.begin(), _alpha.end()), _alpha.end());

    // Build k-grams and k-plus-one-grams
    for (unsigned int i = 1; i < text.length()+1; i++) {
        std::string kgram_str, kplus_str, wrap_str;
        int wrap_len;

        kgram_back = i+k-1;  // this is why we start index at 1
       
        // Get current kgram: wraparound + append, if necessary
        // Get current kplus: based on kgram
        if (kgram_back >= text.length()) {
            wrap_len = kgram_back - text.length() + 1;
            wrap_str = text.substr(0, wrap_len);
            kgram_str = text.substr(i, text.length()-1) + wrap_str;
            kplus_str = kgram_str + text.at(wrap_len);
        } else {
            kgram_str = text.substr(i, k); 
            if (kgram_back+1 >= text.length()) {
                kplus_str = kgram_str + text.at(0);
            } else {
                kplus_str = text.substr(i, k+1);
            }
        }

        // Put kgrams in the map
        std::map<std::string, int>::iterator kg_it = _kgrams.find(kgram_str);
        if (kg_it != _kgrams.end()) {
            kg_it-> second += 1;
//            std::cout << "tallied " << kgram_str;
//            std::cout << "  | count = " << kg_it-> second << std::endl;
        } else {
            _kgrams[kgram_str] = 1;
//            std::cout << "created " << kgram_str;
//            std::cout << "  | count = " << kg_it-> second << std::endl; 
        }

        // Put k-plus-one-grams in the map
        std::map<std::string, int>::iterator kp_it = _kgrams.find(kplus_str);
        if (kp_it != _kgrams.end()) {
            kp_it-> second += 1;
//            std::cout << "tallied " << kplus_str;
//            std::cout << " | count = " << kp_it-> second << std::endl;
        } else {
            _kgrams[kplus_str] = 1;
//            std::cout << "created " << kplus_str;
//            std::cout << " | count = " << kp_it-> second << std::endl;
        }
//        std::cout << std::endl;
    }
}

MarkovModel::~MarkovModel() {
}

// ================================================================== accessors
int MarkovModel::order() {
    return _order;
}

int MarkovModel::freq(std::string kgram) {
    if (_order > kgram.length()) throw std::runtime_error(freq_err);
    std::map<std::string, int>::iterator it = _kgrams.find(kgram);
    if (it != _kgrams.end())
        return it-> second;
    else
       return 0;
}

int MarkovModel::freq(std::string kgram, char c) {
    int frequency = 0;
    
    if (_order == 0) {
        for (unsigned int i = 0; i < _text.length(); i++) {
            if (_text.at(i) == c) frequency++;
        } return frequency;
    }
    
    if (_order != kgram.length()) throw std::runtime_error(freq_err);

    std::string str(1, c);
    std::string kplus = kgram + str;
    std::map<std::string, int>::iterator it = _kgrams.find(kplus);
    if (it != _kgrams.end()) {
        return it-> second;
    } else {
        return 0;
    }
}

char MarkovModel::randk(std::string kgram) {
    // find the total number of kgrams
    int kgram_freq = freq(kgram);
   
    // find the total numbers of each of the k-plus-one-grams 
    std::vector<int> kplus_freqs;
    for (unsigned int i = 0; i < _alpha.length(); i++) {
        
    }

}

std::string MarkovModel::gen(std::string kgram, int t) {

}

// ==================================================================== friends
std::ostream& operator << (std::ostream& os, MarkovModel& mm) {
    std::cout << std::endl << "Order = " << mm._order << std::endl;
    
    std::map<std::string, int>::iterator it;
    for (it = mm._kgrams.begin(); it != mm._kgrams.end(); ++it) {
        if (it->first.length() == mm._order) {
            std::cout << std::endl;
            std::cout << "kgram:      ";
            std::cout << it->first << "   |  frequency: " << it->second;
            std::cout << std::endl;
        } else {
            std::cout << "            ";
            std::cout << it->first << "  ----------->  " << it->second;
            std::cout << std::endl;
        }
    }

    return os;
}





















