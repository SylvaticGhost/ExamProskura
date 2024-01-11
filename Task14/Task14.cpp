#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Функція для зчитування матриці з файлу
vector<vector<int> > readMatrixFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    int n, m;
    file >> n >> m;

    vector<vector<int> > matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return matrix;
}

// Функція для знаходження максимального значення в кожному рядку матриці
vector<int> findMaxValuesInRows(const vector<vector<int> >& matrix) {
    vector<int> maxValues;

    for (const auto& row : matrix) {
        int maxVal = row[0];
        for (int val : row) {
            if (val > maxVal) {
                maxVal = val;
            }
        }
        maxValues.push_back(maxVal);
    }

    return maxValues;
}

// Функція для запису максимальних значень у файл
void writeMaxValuesToFile(const string& filename, const vector<int>& maxValues) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    for (int value : maxValues) {
        file << value << " ";
    }
    file << endl;

    file.close();
}

int main() {
    string inputFilename = "task14_input.txt";
    string outputFilename = "task14_output.txt";

    // Зчитування матриці з файлу
    vector<vector<int> > matrix = readMatrixFromFile(inputFilename);

    // Знаходження максимальних значень в кожному рядку
    vector<int> maxValues = findMaxValuesInRows(matrix);

    // Запис максимальних значень у файл
    writeMaxValuesToFile(outputFilename, maxValues);

    return 0;
}
