#include <iostream>
#include <fstream>

using namespace std;

vector<string> readFile(const string& filename){
    fstream file;
    string line;
    vector<string> text;

    file.open(filename, ios::in);
    do {
        getline(file, line);
        text.push_back(line);
    } while (!line.empty());

    return text;

}

int *calculateParams(string line){
    static int countParams[4] = {0,0,0, 0};
    string curWord = "";
    bool isNumber = true;
    for(int i=0;i<line.length();i++){
        if(line[i] == ' ' || i == line.length()-1){
            if(!curWord.empty()){
                if(isNumber){
                    if(stoi(curWord) > 0){
                        countParams[0] += 1;
                    } else if(stoi(curWord) < 0){
                        countParams[1] += 1;
                    } else{
                        countParams[2] += 1;
                    }
                } else {
                    countParams[3] += 1;
                }
            }
            curWord = "";
            isNumber = true;
            continue;
        }
        if(isNumber && !isdigit(line[i]) && line[i] != '-'){
            isNumber = false;
        }
        curWord += line[i];
    }

    return countParams;
}

void writeToFile(string curString){
    fstream file;
    file.open("task16_output.txt", std::ios_base::app);
    file << curString;
    file.close();
}

int main(){
    vector<string> lines;
    lines = readFile("task16_input.txt");
    for(int i=0;i<lines.size()-1;i++){
        int *countParams;
        countParams = calculateParams(lines[i]);
        string curString = "Positive Numbers: "+to_string(countParams[0])+"; Negative Numbers: "+ to_string(countParams[1])+"; 0 Numbers: "+
                           to_string(countParams[2])+"; Char symbols: "+ to_string(countParams[3])+";\n";
        writeToFile(curString);
    }
}