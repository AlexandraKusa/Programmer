#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int countVowels(const string& word) {
    int count = 0;
    string vowels = "aeiouAEIOU";
    for (char c : word) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

void processText(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string word;
    vector<string> longestWords(3, "");
    vector<int> longestWordCounts(3, 0);
    map<string, int> wordCountMap;

    while (inputFile >> word) {
        if (countVowels(word) > 2) {
            outputFile << word << " " << word << " ";
        } else {
            outputFile << word << " ";
        }

        wordCountMap[word]++;

        for (int i = 0; i < 3; i++) {
            if (word.length() > longestWords[i].length()) {
                for (int j = 2; j > i; j--) {
                    longestWords[j] = longestWords[j-1];
                    longestWordCounts[j] = longestWordCounts[j-1];
                }
                longestWords[i] = word;
                longestWordCounts[i] = wordCountMap[word];
                break;
            } else if (word.length() == longestWords[i].length()) {
                if (wordCountMap[word] > longestWordCounts[i]) {
                    longestWords[i] = word;
                    longestWordCounts[i] = wordCountMap[word];
                }
                break;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Three longest words and their counts:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << longestWords[i] << " - " << longestWordCounts[i] << endl;
    }
}

bool sentenceContainsWord(const string& sentence, const string& word) {
    return sentence.find(word) != string::npos;
}

void processSentences(const string& inputFileName, const string& word) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        if (sentenceContainsWord(line, word)) {
            cout << line << endl;
        }
    }

    inputFile.close();
}

void deleteBetweenOccurrences(const string& inputFileName, const string& word, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    size_t firstPos = content.find(word);
    size_t lastPos = content.rfind(word);

    if (firstPos == string::npos || lastPos == string::npos || firstPos == lastPos) {
        cout << "Error: The word does not appear or appears only once in the file." << endl;
        return;
    }

    string result = content.substr(0, firstPos + word.length()) + content.substr(lastPos);
    outputFile << result;

    inputFile.close();
    outputFile.close();
}

void createAndSortStrings(const string& inputFileName1, const string& inputFileName2, const string& outputFileName) {
    ifstream inputFile1(inputFileName1);
    ifstream inputFile2(inputFileName2);
    ofstream outputFile(outputFileName);

    if (!inputFile1.is_open() || !inputFile2.is_open() || !outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    vector<string> words1;
    vector<string> words2;

    string word;
    while (inputFile1 >> word) {
        words1.push_back(word);
    }
    
    while (inputFile2 >> word) {
        words2.push_back(word);
    }

    if (words1.size() != words2.size()) {
        cout << "Error: The number of words in the two files does not match." << endl;
        return;
    }

    vector<string> combinedWords = words1;
    combinedWords.insert(combinedWords.end(), words2.begin(), words2.end());
    sort(combinedWords.begin(), combinedWords.end());

    outputFile << "s1: ";
    for (const string& w : words1) {
        outputFile << w << " ";
    }
    outputFile << endl;

    outputFile << "s2: ";
    for (const string& w : words2) {
        outputFile << w << " ";
    }
    outputFile << endl;

    outputFile << "s3 (sorted): ";
    for (const string& w : combinedWords) {
        outputFile << w << " ";
    }
    outputFile << endl;

    inputFile1.close();
    inputFile2.close();
    outputFile.close();
}

void menu() {
    string inputFileName = "z1.txt";
    string outputFileName;
    string specificWord;
    int choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Process text (duplicate words with more than 2 vowels, find 3 longest words)" << endl;
        cout << "2. Process sentences (find sentences containing a specific word)" << endl;
        cout << "3. Delete characters between first and last occurrence of a word" << endl;
        cout << "4. Create and sort strings from two files" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter output file name for processed text: ";
                cin >> outputFileName;
                processText(inputFileName, outputFileName);
                break;
            case 2:
                cout << "Enter word to search for in sentences: ";
                cin >> specificWord;
                processSentences(inputFileName, specificWord);
                break;
            case 3:
                cout << "Enter the word to find: ";
                cin >> specificWord;
                cout << "Enter output file name for result: ";
                cin >> outputFileName;
                deleteBetweenOccurrences(inputFileName, specificWord, outputFileName);
                break;
            case 4:
                {
                    string inputFileName2;
                    cout << "Enter the second input file name: ";
                    cin >> inputFileName2;
                    cout << "Enter output file name for sorted result: ";
                    cin >> outputFileName;
                    createAndSortStrings(inputFileName, inputFileName2, outputFileName);
                }
                break;
            case 5:
                return; 
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}

