#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool isVowel(char ch) {
    ch = std::tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'|| ch == 'y');
}

std::string processText(const std::string& line) {
    std::string result;
    bool newWord = true;

    for (size_t i = 0; i < line.length(); ++i) {
        char c = line[i];

        if (std::isalpha(c)) {
            if (newWord) {
                if (isVowel(c)) {
                    c = std::tolower(c);
                }
                newWord = false;
            }
        } else {
            newWord = true;
        }
        result += c;
    }

    return result;
}

int main() {
    std::string filename;
    std::cout << "Input filename: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "error open!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string processedLine = processText(line);
        std::cout << processedLine << std::endl;
    }

    file.close();
    return 0;
}