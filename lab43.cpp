#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int countVowels(const string &word) {
    const string vowels = "aeiouAEIOU";
    int count = 0;
    for (size_t i = 0; i < word.length(); ++i) {
        if (vowels.find(word[i]) != string::npos) {
            count++;
        }
    }
    return count;
}

// ??????? ??? ????????? ???? ? ?????? ??? ????? ????????? ????????
string doubleWordsWithMoreThanTwoVowels(const string &text) {
    stringstream ss(text);
    string word;
    string result;
    while (ss >> word) {
        if (countVowels(word) > 2) {
            result += word + " " + word + " ";
        } else {
            result += word + " ";
        }
    }
    return result;
}

// ??????? ??? ??????????? ????? ????????? ???? ?? ?? ?????????
void findThreeLongestWords(const string &text, map<string, int> &longestWords) {
    istringstream iss(text);
    string word;
    while (iss >> word) {
        if (longestWords.size() < 3) {
            longestWords[word]++;
        } else if (word.size() == longestWords.begin()->first.size()) {
            longestWords[word]++;
        } else {
            break;
        }
    }
}

// ??????? ??? ????????? ??????, ??? ??????? ?????? ?????
void printSentencesWithWord(const string &text, const string &searchWord) {
    stringstream ss(text);
    string sentence;
    while (getline(ss, sentence, '.')) {
        if (sentence.find(searchWord) != string::npos) {
            cout << sentence << "." << endl;
        }
    }
}

// ??????? ??? ????????? ???? ???????? ??? ?????? ?? ???????? ?????????? ?????
string removeCharactersBetweenFirstAndLastAppearance(const string &text, const string &searchWord) {
    size_t firstAppearance = text.find(searchWord);
    size_t lastAppearance = text.rfind(searchWord);
    if (firstAppearance != string::npos && lastAppearance != string::npos && firstAppearance != lastAppearance) {
        return text.substr(0, firstAppearance) + searchWord + text.substr(lastAppearance + searchWord.length());
    } else {
        throw "The word does not exist in the string or appears only once!";
    }
}

// ??????? ??? ??'??????? ???? ? ??????????? ???????
string mergeWordsInAlphabeticalOrder(const string &text1, const string &text2) {
    stringstream ss1(text1);
    stringstream ss2(text2);
    vector<string> words;
    string word;
    while (ss1 >> word) {
        words.push_back(word);
    }
    while (ss2 >> word) {
        words.push_back(word);
    }
    sort(words.begin(), words.end());
    stringstream result;
    for (size_t i = 0; i < words.size(); ++i) {
        result << words[i] << " ";
    }
    return result.str();
}

// ??????? ??? ?????? ?????? ? ????
void writeToFile(const string &fileName, const string &text) {
    ofstream file(fileName.c_str());
    file << text;
    file.close();
}

int main() {
    string fileName1, fileName2, fileName3, fileName4, searchWord;
    cout << "Enter the name of the first file: ";
    cin >> fileName1;
    cout << "Enter the name of the second file: ";
    cin >> fileName2;
    cout << "Enter the name of the third file: ";
    cin >> fileName3;
    cout << "Enter the name of the fourth file: ";
    cin >> fileName4;

    ifstream file1(fileName1.c_str());
    stringstream buffer;
    buffer << file1.rdbuf();
    string text = buffer.str();
    file1.close();

    map<string, int> longestWords;
    findThreeLongestWords(text, longestWords);
    string longestWordsText;
    for (map<string, int>::iterator it = longestWords.begin(); it != longestWords.end(); ++it) {
        longestWordsText += it->first + " - " + to_string(it->second) + "\n";
    }

    cout << "Enter a word to search in the file: ";
    cin >> searchWord;

    string resultA = doubleWordsWithMoreThan

