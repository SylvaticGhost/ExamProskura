#include <iostream>

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
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            matrix[i][j] = 0;
        }
    }
}

int getVal(int k){
    return k;
}
void populateSelectedAreas(int **matrix, int size){
    int k = 0;
    for(int i=0; i<=ceil(size/2); i++) {
        for (int j = i; j < (size - i); j++) {
            k++;
            matrix[i][j] = getVal(k);
        }
    }
    for(int i=floor(size/2); i<size; i++) {
        for (int j = size-i-1; j <= i; j++) {
            if(i==floor(size/2) && size % 2 == 1){
                continue;
            }
            k++;
            matrix[i][j] = getVal(k);
        }
    }
}

int main() {
    const int size = 21;
    int **matrix = new int*[size];
    for(int i=0;i<size;i++){
        matrix[i] = new int[size];
    }
    populateMatrix(matrix, size);
    printMatrix(matrix, size);
    populateSelectedAreas(matrix, size);
    printMatrix(matrix,size);

    delete[] matrix;
}

