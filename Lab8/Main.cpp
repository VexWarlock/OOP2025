#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;



//functie care transforma un string in lowercase
string toLower(const string& str) {
    string lowerStr;
    for (char ch : str)
        lowerStr += tolower(ch);
    return lowerStr;
}


//functie care verifica daca un caracter e separator
bool isSeparator(char ch) {
    return ch == ' ' || ch == ',' || ch == '.' || ch == '?' || ch == '!' || ch == '\n';
}



//impartire pe cuvinte
vector<string> splitIntoWords(const string& text) {
    vector<string> words;
    string word;
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


//comparator
struct WordCompare {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second==b.second)
            return a.first > b.first; //le luam lexicografic
        return a.second < b.second;   //altfel,le luam dupa frecventa
    }
};

int main() {
    ifstream file("input.txt");
    
    string line,text;
    while (getline(file,line)) {
        text+=line+" ";
    }

//facem vector de cuvinte cu cuvintele din prop
    vector<string> words=splitIntoWords(text);

//parcurgem cuvintele si le crestem numarul de aparitii
    map<string,int> wordCount;
    for (const string& word : words) 
        wordCount[word]++;

//facem coada cu prioritati
    priority_queue<pair<string, int>, vector<pair<string,int>>,WordCompare> pq;
    for (const auto& pair : wordCount) {
        pq.push(pair);
    }

//afisam continutul cozii in formatul "cuv => nraparitii"
    while (!pq.empty()) {
        cout << pq.top().first << " => " << pq.top().second << "\n";
        pq.pop();
    }

    return 0;
}
