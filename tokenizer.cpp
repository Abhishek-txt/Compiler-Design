#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string myText;

  ifstream MyReadFile("input.txt");

  while (getline(MyReadFile, myText)) {

    int i = 0;
    while (i < myText.length()) {
      char c = myText[i];

      if (c == ' ' || c == '\t' || c == '\r') {
        i++;
      }

      else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        string word = "";
        while (i < myText.length() && ((myText[i] >= 'a' && myText[i] <= 'z') ||
               (myText[i] >= 'A' && myText[i] <= 'Z') ||
               (myText[i] >= '0' && myText[i] <= '9'))) {
          word = word + myText[i];
          i++;
        }
        if (word == "int" || word == "float" || word == "return" ||
            word == "main" || word == "cout" || word == "endl")
          cout << "Keyword     : " << word << "\n";
        else
          cout << "Identifier  : " << word << "\n";
      }

     
      else if (c >= '0' && c <= '9') {
        string number = "";
        while (i < myText.length() && ((myText[i] >= '0' && myText[i] <= '9') || myText[i] == '.')) {
          number = number + myText[i];
          i++;
        }
        cout << "Number      : " << number << "\n";
      }

      else if (c == '"') {
        string text = "\"";
        i++;
        while (i < myText.length() && myText[i] != '"') {
          text = text + myText[i];
          i++;
        }
        text = text + "\"";
        i++;
        cout << "String      : " << text << "\n";
      }

      else if (c == '<' && i + 1 < myText.length() && myText[i + 1] == '<') {
        cout << "Operator    : <<" << "\n";
        i = i + 2;
      }

      else if (c == '=') {
        cout << "Operator    : =" << "\n";
        i++;
      }

      else {
        cout << "Punctuation : " << c << "\n";
        i++;
      }
    }
  }

  MyReadFile.close();
}
