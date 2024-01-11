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

void print_vector(vector<int> &vect)
 {
	for(const int i:vect)
	{
		cout << i << " ";
	}
	 cout << "\n";
 }

int* generate_array(int size)
{
	random_device random;
	mt19937 generator(random());
	uniform_int_distribution<> distribution(1, 9);

	int* array = new int[size];

	for(int i = 0; i < size; i++)
	{
		array[i] = distribution(generator);
	}

	return array;
}

int main()
{
	const int rows = 5;
	const int columns = 5;

	int** matrix = new int* [rows];

	for(int i = 0; i < rows; i++)
	{
		matrix[i] = generate_array(columns);
	}

	cout << "generated matrix: \n";
	print_matrix(matrix, rows, columns);

	vector<int> answer;

	int lim_j = 1;//the max value of column argument (j) in each rows

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < lim_j; j++)
		{
			if (matrix[i][j] % 2 == 1)
				answer.push_back(matrix[i][j]);
		}
		lim_j++;
	}

	cout << "answer:\n";
	print_vector(answer);

	return 0;
}