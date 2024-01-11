#include <iostream>
#include <random>

using namespace std;

void printMatrix(int **matrix, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            int val = matrix[i][j];
            if(val >= 100){
                cout << val << "  ";
            } else if (val >= 10) {
                cout <<  val << "   ";
            } else {
                cout << " " << val << "   ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void populateMatrix(int **matrix, int size){
    srand(time(NULL)); // NOLINT(cert-msc30-c, cert-msc51-cpp)
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            matrix[i][j] = rand() % 500; // NOLINT(cert-msc30-c, cert-msc50-cpp)
        }
    }
}

void printTriangle(int **matrix, int size){
    for(int i=0; i<=ceil(size/2); i++){
        for(int k=0;k<i;k++){
            cout << "     ";
        }
        for(int j=i;j<(size-i);j++){
            int val = matrix[i][j];
            if(val >= 100){
                cout << val << "  ";
            } else if (val >= 10) {
                cout <<  val << "   ";
            } else {
                cout << " " << val << "   ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void calculate(int **matrix, int size){
    printTriangle(matrix, size);
    for(int i=0; i<=ceil(size/2); i++) {
        for (int j = i; j < (size - i); j++) {
            int val = matrix[i][j];
            if(val == 11 || val == 22 || val == 33 || val == 44 || val == 55 || val == 66 || val == 77 || val == 88 || val == 99){
                cout << "Palindrome " << val << " was found on row " << (i+1) << " column " << j << endl;
            }
        }
    }
}

int main() {
    const int size = 30;
    int **matrix = new int*[size];
    for(int i=0;i<size;i++){
        matrix[i] = new int[size];
    }
    populateMatrix(matrix, size);
    printMatrix(matrix, size);
    calculate(matrix, size);

    delete[] matrix;
}

