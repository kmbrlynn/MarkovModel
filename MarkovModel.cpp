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
       
        // Get current kgram: wraparound + append, if necessary
        // Get current kplus: based on kgram
        if (kgram_back >= text.length()) { 
            wrap_back = kgram_back - text.length();
            wrap_str = text.substr(0, wrap_back);
            kgram_str = text.substr(i, text.length()-1);
            kgram_str.append(wrap_str);
            kplus_str = kgram_str + text.at(wrap_back+1);
        } else {
            kgram_str = text.substr(i, k); 
            if (kgram_back+1 == text.length()) {
                kplus_str = kgram_str + text.at(0);
            } else {
                kplus_str = text.substr(i, k+1);
            }
        }

        // Put kgrams in the map
        std::map<std::string, int>::iterator kg_it = _kgrams.find(kgram_str);
        if (kg_it != _kgrams.end()) {
            kg_it-> second += 1;
 //           std::cout << "tallied kgram: " << kgram_str << std::endl;
        } else {
            _kgrams[kgram_str] = 1;
 //           std::cout << "created kgram " << kgram_str << std::endl; 
        }

        // Put k-plus-one-grams in the map
        std::map<std::string, int>::iterator kp_it = _kgrams.find(kplus_str);
        if (kp_it != _kgrams.end()) {
            kp_it-> second += 1;
 //           std::cout << "tallied kplus: " << kplus_str << std::endl;
        } else {
            _kgrams[kplus_str] = 1;
 //           std::cout << "created kplus " << kplus_str << std::endl;
        }
 //       std::cout << std::endl;
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
   
    std::string str(1, c);
    std::string kplus = kgram + str;

    std::cout << kplus << std::endl;

    std::map<std::string, int>::iterator it = _kgrams.find(kplus);
    if (it != _kgrams.end()) {
        return it-> second;
    } else {
        return 0;
    }
}

char MarkovModel::randk(std::string kgram) {

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





















