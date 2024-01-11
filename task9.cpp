#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <windows.h>

using namespace std;

const int MAX_SIZE = 100;

void generateRandomMatrix(char matrix[MAX_SIZE][MAX_SIZE], int n, const char* alphabet, int alphabetSize) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Генеруємо випадковий індекс в алфавіті
            int randomIndex = rand() % alphabetSize;
            matrix[i][j] = alphabet[randomIndex];
        }
    }
}
void printMatrix(char matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void changedMatrix(char matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    const char* alphabet = "AB";

    cout << "Введіть розмір матриці (n): ";
    cin >> n;
    char matrix[MAX_SIZE][MAX_SIZE];

    generateRandomMatrix(matrix, n, alphabet, strlen(alphabet));

    cout << "Згенерована матриця:" << endl;
    printMatrix(matrix, n);



    return 0;
}
