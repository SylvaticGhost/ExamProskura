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
    return index; // TODO Just fix o everything is printed pretty. If you want real data - comment/remove this exact line
    return int(pow(index, index));
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
    int curY = rows-1;
    char dir;

    for(int filled=0;filled<rows*cols;filled++){
        if(curX == 0 && curY == rows-1){
            matrix[0][0] = getElem(0);
            dir = 'd';
            movePosition(&curX, &curY, dir);
            continue;
        }

        matrix[rows-curY-1][curX] = getElem(filled);
        movePosition(&curX, &curY, dir);
        printMatrix(matrix, rows, cols);

        if((dir == 'd' && curY == 0) || (dir == 'u' && curY == rows-1)){
            dir = 'r';
        } else if(dir == 'r' && curY == 0){
            dir = 'u';
        } else if(dir == 'r' && curY == rows-1){
            dir = 'd';
        }
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

