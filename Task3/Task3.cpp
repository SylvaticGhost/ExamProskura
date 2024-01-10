#include <iostream>
#include <queue>
#include <random>

using namespace std;

class MyBooleanAlgebra
{
    //Algebra defined on {00, 01, 10, 11 and operation PlusOnModel
public:
    bool first_digit;
    bool second_digit;

    MyBooleanAlgebra(bool v1, bool v2)
    {
        first_digit = v1;
        second_digit = v2;
    }

    void PlusOnModule() //00 10 11
    {
        if (second_digit == false)
            second_digit = true;
        else
        {
            if (first_digit == false)
                first_digit = true;
            else
            {
                first_digit = false;
                second_digit = false;
            }

        }
    }
};


class Cords
{
public:
    int x, y, lim_left_x = 0, lim_left_y = 0, lim_right_x, lim_right_y;

    MyBooleanAlgebra direction = MyBooleanAlgebra(false, false);
    
    Cords(int x_in, int y_in, int lim_right_x_in, int lim_right_y_in)
    {
        x = x_in;
        y = y_in;
        lim_right_x = lim_right_x_in;
        lim_right_y = lim_right_y_in;
    }

    bool step_right()
    {
        if (x < lim_right_x)
        {
	        x++;
            return true;
        }
        return false;
    }

    bool step_upper()
    {
	    if(y > lim_left_y)
	    {
            y--;
            return true;
	    }
        return false;
    }

    bool step_left()
    {
	    if(x > lim_left_x)
	    {
            x--;
            return true;
	    }
        return false;
    }

    bool step_down()
    {
	    if(y < lim_right_y)
	    {
            y++;
            return true;
	    }
        return false;
    }

    bool positive() const
    {
        if (x >= 0 & y >= 0)
            return true;
        
        return false;
    }

    void print()
    {
        cout << x << " " << y << "\n";
    }
};

void fill_queue(queue<int> &q, int size)
{
    random_device random;
    mt19937 generator(random());
    uniform_int_distribution<> distribution(1, 3);  

    for (int i = 0; i < size; i++) {
        q.push(distribution(generator) * 3);
    }
}

void print_queue(queue<int> &q)
{
    queue<int> q2(q);

    while(!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << "\n";
}

void fill_matrix(int** &matrix, int r, int c)
{
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
            matrix[i][j] = 0;
		}
	}
}

void sign_value(int** &matrix, queue<int> &q, Cords &c)
{
    if (!q.empty())
    {
        int val = q.front();
        q.pop();
        matrix[c.y][c.x] = val;
    }
    else
        matrix[c.y][c.x] = -1;
}

void print_matrix(int** &matrix, int r, int c)
{
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
            cout << matrix[i][j] << " ";
		}
        cout << "\n";
	}
}


int main()
{
    constexpr int rows = 5;
    constexpr int columns = 5;
       
    queue<int> q;
    fill_queue(q, rows * columns);
    cout << "print queue: \n";
    print_queue(q);

    int** matrix = new int*[rows];

    for(int i = 0; i < rows; i++)
    {
        matrix[i] = new int[columns];
    }

    fill_matrix(matrix, rows, columns);

    Cords cord = Cords(0, rows - 1, columns - 1, rows - 1);

    sign_value(matrix, q, cord);
	while(!q.empty())
    {
        //right
    	while(cord.step_right())
    	{
            sign_value(matrix, q, cord);
            cord.print();
    	}
        cord.lim_right_y = cord.lim_right_y - 1;

        //Up
        while(cord.step_upper())
        {
            sign_value(matrix, q, cord);
            cord.print();
        }
        cord.lim_right_x = cord.lim_right_x - 1;

        //left
        while(cord.step_left())
        {
            sign_value(matrix, q, cord);
            cord.print();
        }
        cord.lim_left_y = cord.lim_left_y + 1;

        while(cord.step_down())
        {
            sign_value(matrix, q, cord);
            cord.print();
        }
        cord.lim_left_x = cord.lim_left_x + 1;
    }

    cout << "matrix: \n";
    
    print_matrix(matrix, rows, columns);


    
	

    
}











