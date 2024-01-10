//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct cords {
//    int x;
//    int y;
//    int limX;
//    int limY;
//};
//
//
//void PrintMatrix(int**& matrix, int r, int c) {
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << "\n";
//    }
//}
//
//
//bool StepDiagonalRightUp(cords& c) {
//    if (c.x < c.limX && c.y > 0) {
//        c.x = c.x + 1;
//        c.y = c.y - 1;
//        return true;
//    }
//    return false;
//}
//
//
//bool StepDiagonalLeftDown(cords& c) {
//    if (c.x > 0 && c.y < c.limY) {
//        c.x = c.x - 1;
//        c.y = c.y + 1;
//        return true;
//    }
//    return false;
//}
//
//
//bool StepUp(cords& c) {
//    if (c.y > 0) {
//        c.y = c.y - 1;
//        return true;
//    }
//
//    return false;
//}
//
//
//bool StepLeft(cords& c) {
//    if (c.x > 0)
//    {
//        c.x = c.x - 1;
//        return true;
//    }
//    return false;
//}
//
//int main() {
//    int column = 5;
//    int row = 5;
//
//    int** matrix = new int* [row];
//
//    for (int i = 0; i < row; i++)
//        matrix[i] = new int[column];
//
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < column; j++)
//            matrix[i][j] = i + j;
//    }
//
//    PrintMatrix(matrix, row, column);
//
//    vector<int> list;
//    int i = row - 1;
//    int j = column - 1;
//
//    cords cord{
//        cord.x = i,
//        cord.y = j,
//        cord.limX = column - 1,
//        cord.limY = row - 1
//
//    };
//
//    while (cord.x >= 0 && cord.y >= 0)
//    {
//        while (cord.x < column && cord.y >= 0) {
//            list.push_back(matrix[cord.x][cord.y]);
//            if (!StepDiagonalRightUp(cord))
//            {
//                list.push_back(matrix[cord.x][cord.y]);
//                break;
//
//            }
//        }
//
//        if (!StepLeft(cord))
//            if (!StepUp(cord))
//                break;
//
//        while (cord.y < row && cord.x >= 0) {
//            list.push_back(matrix[cord.x][cord.y]);
//            if (!StepDiagonalLeftDown(cord))
//            {
//                list.push_back(matrix[cord.x][cord.y]);
//                break;
//            }
//        }
//
//        if (!StepUp(cord))
//            if (!StepLeft(cord))
//                break;
//    }
//    cout << "print list" << "\n";
//    for (int e : list)
//        cout << e << " ";
//
//    return 0;
//}

#include <iostream>

using namespace std;

int main() {

    int n;
    cout << "размер матрицы: ";
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }


    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = a[j + i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] a;

    return 0;
}

