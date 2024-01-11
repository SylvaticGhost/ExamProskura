#include <iostream>
#include <random>

using namespace std;

void print_matrix(int**& matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
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
	const int size = 5;

	int** matrix = new int* [size];

	for (int i = 0; i < size; i++)
	{
		matrix[i] = generate_array_byElement(size, 0);
	}

	int number = 1;
	int lim_j = size;
	int start_j = 0;

	for(int i = size - 1; i >= floor(size / 2); i--)
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
	print_matrix(matrix, size);

}

