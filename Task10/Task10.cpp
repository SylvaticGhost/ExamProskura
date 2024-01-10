#include <iostream>
#include <random>

using namespace std;

void print_matrix(int**& matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void print_vector(vector<int>& vect)
{
	for (const int i : vect)
	{
		cout << i << " ";
	}
	cout << "\n";
}

int* generate_array_byElement(int size, int element)
{
	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = element;
	}

	return array;
}

int main()
{
	constexpr int rows = 5;
	constexpr int columns = 5;

	int** matrix = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = generate_array_byElement(columns, 0);
	}

	int number = 1;
	int lim_j = columns;
	int start_j = 0;

	for(int i = rows - 1; i >= floor(rows / 2); i--)
	{
		for(int j = start_j; j < lim_j; j++)
		{
			matrix[i][j] = number;
			number++;
		}
		start_j++;
		lim_j--;
	}

	cout << "matrix: \n";
	print_matrix(matrix, rows, columns);

}

