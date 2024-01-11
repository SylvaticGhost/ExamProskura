#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> read_file(const string &path)
{
	fstream file;
	string line;
	vector<string> text;

	file.open(path, ios::in);

	do
	{
		getline(file, line);
		text.push_back(line);
	} while (!line.empty());

	file.close();
	return text;
}

void write_file(string& path, string &text)
{
	fstream file;
	file.open(path, ios::out);

	if(file.is_open())
	{
		file << text;
	}

	file.close();
}

int main()
{
	string containing;

	string path1 = "Prices.txt";
	string path2 = "Numbers.txt";
	string path3 = "Result.txt";

	vector<string> numbers = read_file(path2);
	vector<string> prices = read_file(path1);

	
	cout << numbers.size();
	for(int i = 0; i < numbers.size() - 1; i++)
	{
		string name, num, price;
		int j = 0;
		while(numbers[i][j] != ' ')
		{
			name += numbers[i][j];
			j++;
		}
		j++;
		int k = j;
		while(j < numbers[i].size())
		{
			num += numbers[i][j];
			j++;
		}

		while(k < prices[i].size())
		{
			price += prices[i][k];
			k++;
		}

		containing.append(name + ' ' + num + ' ' + price + '\n');
	}

	write_file(path3, containing);

}


