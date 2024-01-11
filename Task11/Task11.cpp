#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Функція для видалення однолітерних слів та зайвих символів
string removeSingleChars(const string& input) {
    istringstream iss(input);
    ostringstream oss;
    string word;

    while (iss >> word) {
        if (word.length() > 1) {
            oss << word << ' ';
        }
    }

    return oss.str();
}

// Функція для визначення кількості слів та знаходження найдовшого слова
void analyzeString(const string& input, int& wordCount, string& longestWord) {
    istringstream iss(input);
    string word;
    wordCount = 0;
    longestWord = "";

    while (iss >> word) {
        if (word.length() > 1) {
            wordCount++;
            if (word.length() > longestWord.length()) {
                longestWord = word;
            }
        }
    }
}

int main() {
    string inputString;
    cout << "Input string: ";
    getline(cin, inputString);

    // Видалення однолітерних слів та зайвих символів
    string processedString = removeSingleChars(inputString);

    int wordCount;
    string longestWord;

    // Аналіз рядка
    analyzeString(processedString, wordCount, longestWord);

    // Виведення результатів
    cout << "Words count: " << wordCount << endl;
    cout << "Longest word: " << longestWord << endl;

    // Запис результатів у текстовий файл
    ofstream outputFile("task11_result.txt");
    if (outputFile.is_open()) {
        outputFile << "Words count: " << wordCount << endl;
        outputFile << "Longest word: " << longestWord << endl;
        outputFile.close();
        cout << "Results saved in file result.txt" << endl;
    } else {
        cerr << "Unable to open file for writing" << endl;
        return 1;
    }

    return 0;
}
