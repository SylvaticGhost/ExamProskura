#include <iostream>
#include <queue>
#include <random>

using namespace std;

class Cords
{
private:
    int start_x;
    int start_y;

public:
    int x;
    int y;
    int lim_x;
    int lim_y;

    Cords(int in_x, int in_y, int in_lim_x, int in_lim_y)
    {
        x = in_x;
        y = in_y;
        lim_x = in_lim_x;
        lim_y = in_lim_y;
        start_x = in_x;
        start_y = in_y;
    }

    bool check_cords_oposite_start()
    {
        if (abs(start_x - x) == lim_x && abs(start_y - y) == lim_y)
            return true;

        return false;
    }

    bool step_down()
    {
        if (y < lim_y)
        {
            y++;
            return true;
        }
        return false;
    }

    bool step_left()
    {
        if (x > 0)
        {
            x--;
            return true;
        }
        return false;
    }

    bool step_leftUpper()
    {
        if (y > 0 && x > 0)
        {
            x--;
            y--;
            return true;
        }

        return false;
    }

    bool step_rightDown()
    {
        if (x < lim_x && y < lim_y)
        {
            x++;
            y++;
            return true;
        }
        return false;
    }

    void print() const
    {
        cout << "x: " << x << " y:" << y << "\n";
    }

    bool is_positive() const{
        if (x >= 0 && y >= 0)
            return true;

        return false;
    }
};

void fill_queue(queue<int>& q, int size)
{
    random_device random;
    mt19937 generator(random());
    uniform_int_distribution<> distribution(1, 9);

    for (int i = 0; i < size; i++) {
        q.push(distribution(generator));
    }
}

void print_queue(queue<int>& q) {
    queue<int> q2(q);

    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << "\n";
}

void fill_matrix(int**& matrix, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void print_matrix(int**& matrix, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}


void set_value(int**& matrix, queue<int>& queue1, Cords& cords) {
    if (!queue1.empty()) {
        int value = queue1.front();
        matrix[cords.y][cords.x] = value;
        queue1.pop();
    }
    else
        matrix[cords.y][cords.x] = -1;
}

int main() {
    queue<int> q;
    int columns = 5;
    int rows = 5;
    fill_queue(q, rows * columns);
    cout << "queue: \n";
    print_queue(q);

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }

    fill_matrix(matrix, rows, columns);

    Cords cords = Cords(4, 0, columns - 1, rows - 1);

    set_value(matrix, q, cords);

    while (cords.is_positive()) {

        if (!cords.step_down())
            if (!cords.step_left())
                break;

        set_value(matrix, q, cords);

        while (cords.step_leftUpper()) {
            set_value(matrix, q, cords);
        }

        if (!cords.step_left())
            if (!cords.step_down())
                break;

        set_value(matrix, q, cords);

        while (cords.step_rightDown()) {
            set_value(matrix, q, cords);
        }

    }

    cout << "Matrix: \n";
    print_matrix(matrix, rows, columns);
}
