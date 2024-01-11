#include <iostream>

using namespace std;

void explodeSentence(string str, string *words){
    string curWord; // curWord = ""
    int k=0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ' || i == (str.length()-1)){
            if(i == (str.length()-1)) curWord += str[i];
            words[k] = curWord;
            k++;
            curWord = "";
            continue;
        }
        curWord += str[i];
    }
}

void compareSentences(string *curWords, string *prevWords){
    for(int i=0;i<1000;i++){
        if(curWords[i].empty()){
            break;
        }
        for(int j=0;j<1000;j++){
            if(prevWords[j].empty()){
                break;
            }
            if(curWords[i] == prevWords[j]){
                cout << "Word " << curWords[i] << " has duplicate  comparing with previous sentence" << endl;
            }
        }
    }
}

void sizeNotExceeds(string *words, int maxLength){
    string *wordsNotExceed;
    wordsNotExceed = new string[100];
    int k=0;
    for(int i=0;i<1000;i++) {
        if (words[i].empty()) {
            break;
        }

        if(words[i].length() < maxLength){
            wordsNotExceed[k] = words[i];
            k++;
        }
    }

    bool bubblePending;
    do {
        bubblePending = false;
        for(int i=1;i<k;i++){
            if(wordsNotExceed[i] < wordsNotExceed[i-1]){ // swapping (bubble sort)
                string temp = wordsNotExceed[i];
                wordsNotExceed[i] = wordsNotExceed[i-1];
                wordsNotExceed[i-1] = temp;
                bubblePending = true;
            }
        }
    } while (bubblePending);


    cout << "Words in the limit of N sorted: ";
    for(int i=0;i<k;i++){
        cout << wordsNotExceed[i] << " ";
    }

    cout << endl;

    delete[] wordsNotExceed;
}

int main() {
    cout << "Hello, world!" << endl;

    int maxLength = 6;
    const int sentencesNumber = 6;
    cout << "Please,  input word max length: ";
    //cin >> maxLength;
    cout << endl;

    string sentences[sentencesNumber] = {
            "word1 word2 word3 word4 word5 lak",
            "word6 word7 word1 word4 word8",
            "word9 word10 word8 word4 word11",
            "word2 word9 word12",
            "foo bar very_long_word s tlf",
            "something_f foo k tlf"
    };

    for(int i=0;i<sentencesNumber;i++){
        cout << endl << "Sentence: " << sentences[i] << endl;
        if((i+1) % 2 == 0){ // even sentences
            string *curSentenceWords;
            curSentenceWords = new string[100];
            string *prevSentenceWords;
            prevSentenceWords = new string[100];
            explodeSentence(sentences[i], curSentenceWords);
            explodeSentence(sentences[i-1], prevSentenceWords);
            compareSentences(curSentenceWords, prevSentenceWords);

            delete[] curSentenceWords;
            delete[] prevSentenceWords;
        } else { // odd sentences
            string *sentenceWords;
            sentenceWords = new string[100];
            explodeSentence(sentences[i], sentenceWords);
            sizeNotExceeds(sentenceWords, maxLength);

            delete[]  sentenceWords;
        }
    }
}

