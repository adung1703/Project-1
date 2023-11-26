#include <iostream>
#include <string>
#include <sstream>

int countWords(const std::string& text) {
    std::istringstream iss(text);
    std::string word;
    int wordCount = 0;

    while (iss >> word) {
        wordCount++;
    }

    return wordCount;
}

int main() {
    std::cout << "Enter the text (Press Ctrl+D to finish input):" << std::endl;
    std::string inputText;
    std::stringstream textStream;

    while (std::getline(std::cin, inputText)) {
        textStream << inputText << "\n";
    }

    int wordCount = countWords(textStream.str());

    std::cout << "Number of words: " << wordCount << std::endl;

    return 0;
}

