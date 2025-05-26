#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>
#include <vector>
#include <algorithm>

// Helper function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string lowerStr;
    for (char ch : str)
        lowerStr += std::tolower(static_cast<unsigned char>(ch));
    return lowerStr;
}

// Helper function to check if a character is a separator
bool isSeparator(char ch) {
    return ch == ' ' || ch == ',' || ch == '.' || ch == '?' || ch == '!' || ch == '\n';
}

// Tokenize string using only std::string methods
std::vector<std::string> splitIntoWords(const std::string& text) {
    std::vector<std::string> words;
    std::string word;
    for (char ch : text) {
        if (isSeparator(ch)) {
            if (!word.empty()) {
                words.push_back(toLower(word));
                word.clear();
            }
        }
        else {
            word += ch;
        }
    }
    if (!word.empty()) {
        words.push_back(toLower(word));
    }
    return words;
}

// Comparator for priority_queue
struct WordCompare {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second == b.second)
            return a.first > b.first; // lexicographically ascending
        return a.second < b.second;   // max-heap on frequency
    }
};

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Error: Could not open file.\n";
        return 1;
    }

    std::string line, text;
    while (std::getline(file, line)) {
        text += line + " ";
    }

    std::vector<std::string> words = splitIntoWords(text);

    std::map<std::string, int> wordCount;
    for (const std::string& word : words) {
        wordCount[word]++;
    }

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, WordCompare> pq;
    for (const auto& pair : wordCount) {
        pq.push(pair);
    }

    while (!pq.empty()) {
        std::cout << pq.top().first << " => " << pq.top().second << "\n";
        pq.pop();
    }

    return 0;
}
