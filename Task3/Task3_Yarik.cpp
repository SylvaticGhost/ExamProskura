#include <iostream>

using namespace std;

void printMatrix(int **matrix, int rowsNumber, int colsNumber){
    for(int i=0;i<rowsNumber;i++){
        for(int j=0;j<colsNumber;j++){
            int val = matrix[i][j];
            if(val >= 10){
                cout << val << " ";
            } else {
                cout << val << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int getElem(int index){
    return (index*3)+3;
}

void movePosition(int *curX, int *curY, char direction){
    if(direction == 'r'){ // right
        (*curX)++;
    } else if(direction == 'l'){ // left
        (*curX)--;
    } else if(direction == 'u'){ // up
        (*curY)++;
    } else if(direction == 'd'){ // down
        (*curY)--;
    }
}

void fillMatrix(int **matrix, int rows, int cols){

    int curX = 0;
    int curY = 0;

    int emptyMaxRight = cols-1;
    int emptyMaxLeft = 0;
    int emptyMaxTop = rows-1;
    int emptyMaxBottom = 0;
    char dir;
    for(int filled=0;filled<rows*cols;filled++){
        if(curX == 0 && curY == 0){
            matrix[rows-curY-1][curX] = getElem(0);
            dir = 'r';
            movePosition(&curX, &curY, dir);
            emptyMaxBottom++;
            continue;
        } else {
            if(dir == 'r' && curX == emptyMaxRight){ // it is on the right border
                emptyMaxRight--;
                dir = 'u';
            } else if(dir == 'u' && curY == emptyMaxTop){
                emptyMaxTop--;
                dir = 'l';
            } else if(dir == 'l' && curX == emptyMaxLeft){
                emptyMaxLeft++;
                dir = 'd';
            } else if(dir == 'd' && curY == emptyMaxBottom){
                emptyMaxBottom++;
                dir = 'r';
            }
        }
        matrix[rows-curY-1][curX] = getElem(filled);
        movePosition(&curX, &curY, dir);
    }
}



int main() {
    const int rows = 6;
    const int cols = 5;
    int **matrix = new int*[rows];
    for(int i=0;i<rows;i++){
        matrix[i] = new int[cols];
    }
    printMatrix(matrix, rows, cols);
    fillMatrix(matrix, rows,cols);
    printMatrix(matrix,rows, cols);

    delete[] matrix;
}

