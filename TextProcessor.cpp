#include "TextProcessor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cctype>

TextProcessor::TextProcessor() : filename("") {
    std::cout << "TextProcessor: конструктор без параметров\n";
}

TextProcessor::TextProcessor(const std::string& fname) : filename(fname) {
    std::cout << "TextProcessor: конструктор с параметрами\n";
}

TextProcessor::TextProcessor(const TextProcessor& other)
    : filename(other.filename) {
    std::cout << "TextProcessor: конструктор копирования\n";
}

TextProcessor::~TextProcessor() {
    std::cout << "TextProcessor: деструктор\n";
}

void TextProcessor::setFilename(const std::string& fname) {
    filename = fname;
}

std::string TextProcessor::getFilename() const {
    return filename;
}

bool TextProcessor::isVowel(char c) const {
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' ||
           c == 'o' || c == 'u' || c == 'y';
}

void TextProcessor::processFile() const {
    std::ifstream file(filename);
    if (!file)
        throw std::runtime_error("Не удалось открыть файл");

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;

        while (ss >> word) {
            char first = word.front();
            char last = word.back();

            if (isVowel(first) && isVowel(last)) {
                std::cout << word << "\n";
            }
        }
    }
}
