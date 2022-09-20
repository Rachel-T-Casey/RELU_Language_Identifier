#include <iostream>
#include <set>
#include <fstream>
#include <clocale>
#include <codecvt>


#include "Network.hpp"

const std::vector<int> BAD_CHARS = {0, 1, 2, 13, 25};
const int MAX_WORD_LENGTH = 16;
const int NUMBER_OF_DICTIONARIES = 4;


void loadUniqueChars(std::wifstream& s, std::set<char8_t>& uniqueChars) {
    std::wstring line;
    while(std::getline(s, line)) {
        for(char8_t c : line) {
            uniqueChars.insert(c);
        }
    }
    return;
}
int getPosition(char8_t c, std::set<char8_t>& uniqueChars) {
    auto it = std::find(uniqueChars.begin(), uniqueChars.end(), c);
    return std::distance(uniqueChars.begin(), it);
}

std::vector<int> buildInputs(std::vector<int>& characterPositions, int uniqueCharCount) {
    std::vector<int> r;
    while(characterPositions.size() > MAX_WORD_LENGTH) {
        characterPositions.pop_back();
    }
    int emptyLetters = MAX_WORD_LENGTH - characterPositions.size();
    int emptyInputs = emptyLetters * uniqueCharCount;
    for(int charPos : characterPositions) {
        for(int i = 0; i < uniqueCharCount; i++) {
            if(i == charPos){
                r.push_back(1);
            } else {
                r.push_back(-1);
            }
        }
    }
    for(int i = 0; i < emptyInputs; i++) {
        r.push_back(0);
    }
    return r;
}
int main(int argc, char const *argv[])
{
    std::wifstream English;
    std::wifstream French;
    std::wifstream German;
    std::wifstream Spanish;

    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>);
    std::setlocale(LC_ALL, "en_US.UTF-8");
   
    std::set<char8_t> uniqueChars;
    wchar_t bom = L'\0';

    English.open("./dataset/English/English");
    English.imbue(utf8_locale);
    English.get(bom);
    loadUniqueChars(English, uniqueChars);
    English.close();

    French.open("./dataset/French/French");
    French.imbue(utf8_locale);
    French.get(bom);
    loadUniqueChars(French, uniqueChars);
    French.close();

    German.open("./dataset/German/German");
    German.imbue(utf8_locale);
    German.get(bom);
    loadUniqueChars(German, uniqueChars);
    German.close();

    Spanish.open("./dataset/Spanish/Spanish");
    Spanish.imbue(utf8_locale);
    Spanish.get(bom);
    loadUniqueChars(Spanish, uniqueChars);
    Spanish.close();
    
    int number_of_inputs = uniqueChars.size() * MAX_WORD_LENGTH;
    std::vector<int> testInput = {4, 1, 4};
    std::vector<int> test = buildInputs(testInput, uniqueChars.size());
 
    Network(number_of_inputs, NUMBER_OF_DICTIONARIES);
}
