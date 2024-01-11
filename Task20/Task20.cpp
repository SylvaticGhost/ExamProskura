#include <clocale>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<string> input_text() {
    cout << "введіть новий рядок, для відправки натисніть ENTER, для закінчення відправте пустий рядок\n";
    vector<string> text = {};
    string line;
    do {
        line = "";
        getline(cin, line);
 
    	text.push_back(line);

    } while (!line.empty());
    cout << "запис закінчено\n";
    text.pop_back();
    return text;
}

string take_string_part(string& s, int begin, int end) {
    string result = "";
    for (int i = begin; i < end; i++) {
        result += s[i];
    }
    return result;
}




void change_lines(vector<string>& text) {
     
    for (int i = 0; i < text.size(); i++) 
    {
        vector<string> words;
        stringstream ss(text[i]);
        string l;

        while (getline(ss, l, ' '))
            words.push_back(l);

        if (text[i].size() <= 60)
        {
            //count a number of spaces
            int spaces = 1;

            if(words.size() > 1)
            {
	            while (text[i].length() + (words.size() - 1) * ++spaces <= 60)
	            	spaces++;
            }

            string newLine = "";

            for(string word:words)
            {
                for (int j = 0; j < spaces; j++)
                    word += ' ';

                newLine.append(word);
            }

            text[i] = newLine;
			
        }
        else {
            string line1;
            int j = 0;

            while(line1.size() + words[j].size() + 1 <= 60)
            {
                words[j] += ' ';
            	line1.append(words[j]);
                j++;
            }

            text[i] = line1;

            string line2;
            while (j < words.size())
            {
                words[j] += ' ';
                line2.append(words[j]);
                j++;
            }

            if (i == text.size() - 1)
                text.push_back(line2);
            else
            {
                text[i + 1].append(line2);
            }
        }
    }
}

void print_text(vector<string>& text) {
    for (string line : text) {
        cout << line << "\n";
    }
}


void write_file(string &path, vector<string> &text)
{
    string t;

    for (string line : text)
        t.append(line + '\n');

	fstream file;
    file.open(path, ios::out);

    if(file.is_open())
    {
        file << t;
    }

    file.close();
}

int main() {
    setlocale(0, "UKR");

    vector<string> text = input_text();
    cout << "записаний текст: \n";
    print_text(text);
    change_lines(text);
    cout << "видозміненний текст: \n";
    print_text(text);

    string path = "F.txt";

    write_file(path, text);


}
