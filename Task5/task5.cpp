#include <iostream>
#include <windows.h>

using namespace std;

// Функція для заповнення матриці у змійці
void fillMatrixSnake(int** matrix, int size, const int* sequence) {
    int counter = 0;

    for (int i = 0; i < size; ++i) {
         // Якщо рядок непарний - заповнюємо його від правого до лівого

        if (i % 2 == 0) {
            for (int j = size - 1; j >= 0; --j) {
                matrix[i][j] = sequence[counter++];
            }
        } else { // Якщо рядок парний - заповнюємо його від лівого до правого
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = sequence[counter++];
            }
        }
    }
}

// Функція для виведення матриці
void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Введення розміру квадратної матриці від користувача
    int size;
    cout << "Введіть розмір квадратної матриці: ";
    cin >> size;

    // Введення послідовності чисел від користувача
    int* userSequence = new int[size * size];
    cout << "Введіть послідовність " << size * size << " чисел для заповнення матриці у змійці:" << endl;
    for (int i = 0; i < size * size; ++i) {
        cin >> userSequence[i];
    }

    // Створення квадратної матриці
    int** matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }

    // Заповнення матриці у змійці
    fillMatrixSnake(matrix, size, userSequence);

    // Виведення матриці
    cout << "Матриця у змійці:" << endl;
    printMatrix(matrix, size);

    // Звільнення пам'яті
    delete[] userSequence;
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
