#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string note() {
    int answer2;
    string text;
    cout << "\nSelect the input method\n";
    cout << "\n1) Keyboard\n";
    cout << "\n2) File (D:\\hello.txt)\n";
    cin >> answer2;

    if (answer2 == 1) {
        cin.ignore();
        getline(cin, text);
    }
    else if (answer2 == 2) {
        ifstream in("D:\\hello.txt"); // окрываем файл для чтения
        if (in.is_open())
        {
            while (getline(in, text))
            {
                cout << "You entered: " << endl;
                cout << text << endl;
            }
        }
        else cout << "File doesn't exist\n";
        in.close();
    }
    return text;
}

string cleaning(string text, int len) {
   
    while (text[0] == '.' || text[0] == ' ') {
        text.erase(0, 1);
        len--;
    }
    while (text[len] == ' ') {
        text.erase(len, 1);
        len--;
    }
    for (int i = 0; i < len; i++) {
        if (text[i] == ' ' && (text[i+1] == ' '|| text[i + 1] == ',' || text[i + 1] == '.'|| text[0] == ' ')) {
                text.erase(i, 1);
                len--;
        }
    }
    for (int i = 0; i < len; i++) {
        if ((text[i] == '.' && text[i + 1] == '.') && text[i + 2] == '.')
            i += 3;
        else if((text[i] == '.' || text[i] == ',' || text[i] == ';' || text[i] == ':' || text[i] == '!' || text[i] == '?') && (text[i+1] == '.' || text[i + 1] == ',' || text[i + 1] == ';' || text[i + 1] == ':' || text[i + 1] == '!' || text[i + 1] == '?')) {
            text.erase(i, 1);
            len--;
            i--;
        }
    }
    for (int i = 0; i < len; i++) {
        if (i == 0)
            text[i] = toupper(text[i]);       
        else 
            text[i] = tolower(text[i]);
    }
    for (int i = 0; i < len; i++) {
        if (text[i] == '.' && text[i + 1] == ' ')
            text[i+2] = toupper(text[i+2]);
    }
    return text;
}

void exerciseThree(string text){
    int End = 0;
    string str, word;
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};

    int len = text.length();
    for (int i = 0; i < len; i++) {
        if ((text[i] == ';' || text[i] == ',' || text[i] == '.' || text[i] == ':' || text[i] == '!' || text[i] == '?')) {
            text.erase(i, 1);
            len--;
            i--;
        }
    }
    str = text;
    cout << "\nAll words containing only letters - ";

    while (End >= 0) {
        bool foundNum = false;
        End = str.find(' ');
        word = str.substr(0, End);
        str = str.erase(0, End + 1);
        for (int i = 0; i < word.length(); i++) {
            for (auto j : numbers)
            if (word[i] == j) {
                foundNum = true;
                break;
            }
        }
        if (!foundNum) {
            cout << word << " ";
        }        
    }
    End = 0;
    str = text;
    cout << "\n\nAll words containing only numbers - ";
    while (End >= 0) {
        bool foundNum = false;
        End = str.find(' ');
        word = str.substr(0, End);
        str = str.erase(0, End + 1);
        for (int i = 0; i < word.length(); i++) {
            for (auto j : letters) {
                if (word[i] == j) {
                    foundNum = true;
                    break;
                }
            }
        }
        if (!foundNum) cout << word << " ";
    }
    End = 0;
    str = text;
    cout << "\n\nAll words containing only numbers and letters - ";
    while (End >= 0) {
        bool foundNum = false;
        End = str.find(' ');
        word = str.substr(0, End);
        str = str.erase(0, End + 1);
        for (int i = 0; i < word.length(); i++) {
            for (auto j : letters) {
                if (word[i] == j) {
                    for (int m = i; m < word.length(); m++) {
                        for (auto k : numbers) {
                            if (word[m] == k) {
                                foundNum = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < word.length(); i++) {
            for (auto j : numbers) {
                if (word[i] == j) {
                    for (int m = i; m < word.length(); m++) {
                        for (auto k : letters) {
                            if (word[m] == k) {
                                foundNum = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (foundNum) cout << word << " ";
    }
}

void exerciseFour(string text) {
    int len = text.length();
    for (int i = 0; i < len; i++) {
        if ((text[i] == ';' || text[i] == ',' || text[i] == '.' || text[i] == ':' || text[i] == '!' || text[i] == '?')) {
            text.erase(i, 1);
            len--;
            i--;
        }
    }
    string word, text2, line;
    text2 = "";
    text += " ";
    int index = 0;
    //cout << text << endl;
    int End = 0;

    while (End >= 0) {
        End = text.find(' ');
        word = text.substr(0, End);
        text = text.erase(0, End + 1);
        if (word.length() < 10) {
            int k = 10 - word.length();
            for (int j = 0; j < k; j++) {
                word += " ";
            }
        }
        text2 += word;
    }
    text2 = text2.erase(text2.length() - 10, text2.length()-1);

    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < text2.length(); i += 10) {
            line += text2[i+j];
            line += " ";
        }
        cout << line << endl;
        line = "";
    }
}

void exerciseFive(string text) {
    string subText;
    bool foundOne = false;
    bool found = true;
    int answer = 1;
    while (answer == 1) {

        cout << "\nEnter substring:" << endl;
        cin.ignore();
        getline(cin, subText);

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == subText[0]) {
                for (int j = 1; j < subText.length(); j++) {
                    if (text[i + j] != subText[j])
                        found = false;
                }
                if (found == true) {
                    cout << "First index of substring - " << i << "\n";
                    foundOne = true;
                }
            }
            found = true;
        }
        if (!foundOne)
            cout << "This subStr doesn't exist";
        cout << "\n\nDo you wanna repeat? (yes - 1; no - 0) (please repeat entering if it isn't true)" << endl;
        cin >> answer;
    }    
}

int main()
{
    int answer1, len;
    answer1 = 1;
    len = 0;
    string text;

    text = note(); // используется функция записи введенного текста (1 задание)

    while (text[len])
        ++len;
    cout << "\nNumber of symbols in the text: " << len << endl;

    text = cleaning(text, len); // 2 задание
    cout << "\nEdited input text:" << endl;
    cout << text << endl;

    exerciseThree(text); 

    cout << "\n\nDisplays all words in the original sequence vertically on the screen:\n" << endl;
    exerciseFour(text); 

    exerciseFive(text);

    return 0;
}

