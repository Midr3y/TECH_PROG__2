#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>

class TextProcessor {
private:
    std::string filename;

    bool isVowel(char c) const;

public:
    TextProcessor();
    TextProcessor(const std::string& fname);
    TextProcessor(const TextProcessor& other);
    ~TextProcessor();

    void setFilename(const std::string& fname);
    std::string getFilename() const;

    void processFile() const;
};

#endif
