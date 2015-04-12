// Copyright Kim Douglas 2015
#include <map>
#include <string>

class MarkovModel {
 public:
    MarkovModel(std::string text, int k);
    ~MarkovModel();
    
    int order();
    int freq(std::string kgram);
    int freq(std::string kgram, char c);
    char randk(std::string kgram);
    std::string gen(std::string kgram, int T);
    
    friend std::ostream& operator <<(std::ostream& os, MarkovModel& mm);

 private:
    int _order;
    std::map <std::string, int> _kgrams;
    std::string _alpha;
};
