#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string myText;
  int lineNo = 0;
  ifstream MyReadFile("input.txt");

  while (getline(MyReadFile, myText)) {

    lineNo++;
    cout << "Line " << lineNo << ": " << myText << "\n";

    int len = myText.length();
    int i = 0;

    while (i < len) {
      char c = myText[i];

      if (c == ' ' || c == '\t' || c == '\r') {
        i++;
      }

      else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
        string word = "";
        while (i < len && ((myText[i] >= 'a' && myText[i] <= 'z') ||
               (myText[i] >= 'A' && myText[i] <= 'Z') ||
               (myText[i] >= '0' && myText[i] <= '9') || myText[i] == '_')) {
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
        int dots = 0;
        bool onlyDigits = true;

        while (i < len && ((myText[i] >= '0' && myText[i] <= '9') ||
               (myText[i] >= 'a' && myText[i] <= 'z') ||
               (myText[i] >= 'A' && myText[i] <= 'Z') ||
               myText[i] == '_' || myText[i] == '.')) {
          if (myText[i] == '.') dots++;
          else if (myText[i] < '0' || myText[i] > '9') onlyDigits = false;
          number = number + myText[i];
          i++;
        }

        bool endsWithDot = (number[number.length() - 1] == '.');

        if (onlyDigits && dots <= 1 && !endsWithDot)
          cout << "Number      : " << number << "\n";
        else
          cout << "Invalid identifier : " << number << "\n";
      }

      else if (c == '"') {
        string text = "\"";
        i++;
        while (i < len && myText[i] != '"') {
          text = text + myText[i];
          i++;
        }
        if (i < len) {
          text = text + "\"";
          i++;
          cout << "String      : " << text << "\n";
        } else {
          cout << "Invalid identifier : " << text << "\n";
        }
      }

      else if (c == '<' && i + 1 < len && myText[i + 1] == '<') {
        cout << "Operator    : <<" << "\n";
        i = i + 2;
      }

      else if (c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '<' || c == '>') {
        cout << "Operator    : " << c << "\n";
        i++;
      }

      else if (c == '(' || c == ')' || c == '{' || c == '}' || c == ';' || c == ',') {
        cout << "Punctuation : " << c << "\n";
        i++;
      }

      else {
        cout << "Invalid identifier : " << c << "\n";
        i++;
      }
    }
    cout << "\n";
  }

  MyReadFile.close();
}