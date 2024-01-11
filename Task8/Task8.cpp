#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

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
    int n;
    const char* alphabet = "AB";

    cout << "Input matrix size (n): ";
    cin >> n;
    char matrix[MAX_SIZE][MAX_SIZE];

    generateRandomMatrix(matrix, n, alphabet, strlen(alphabet));

    cout << "Generated matrix:" << endl;
    printMatrix(matrix, n);



    return 0;
}
