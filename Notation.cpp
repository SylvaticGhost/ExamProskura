//BETTER WAY TO CREATE MATRIX:

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
	constexpr int rows = 5;
	constexpr int columns = 5;

	int** matrix = new int* [rows];

	for(int i = 0; i < rows; i++)
	{
		matrix[i] = generate_array(columns);
	}
	return 0;
}
