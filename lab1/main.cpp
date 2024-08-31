#include "ArgumentManager.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <string>
bool is_pal(string st, int lead, int back) {
  if (lead >= back)
    return true;
  if (st[lead] != st[back])
    return false;
  return is_pal(st, lead + 1, back - 1);
}
// void removespace(string &str) {
//   int i = 0, j = 0;
//   while (str[i]) {
//     if (str[i] != ' ')
//       str[j++] = str[i];
//     i++;
//   }
//   str[j] = '\0';
// }
// void removecomma(string &str, int len) {
//   int j = 0;
//   for (int i = 0; i < len; i++) {
//     if (str[i] != ',') {
//       continue;
//     } else {
//       str[j] = str[i];
//       j++;
//     }
//   }
//   str[j] = '\0';
// }

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  ifstream ifs(am.get("input"));
  ofstream ofs(am.get("output"));
  string str;
  string newStr = "";
  while (getline(ifs, str)) {
    int size = str.length();
    for (int i = 0; i < size; i++) {
      if (isalpha(str[i])) {
        newStr += tolower(str[i]);
      }
    }
  }
  ifs.close();
  // ofs << newStr << endl;
  // ofs << newStr.length() - 1 << endl;
  if (is_pal(newStr, 0, newStr.length() - 1) == true) {
    ofs << "true";
  } else {
    ofs << "false";
  }
  cout << "hello" << endl;
  // ofs << is_pal(newStr, 0, newStr.length() - 1);
  ofs.close();
  return 0;
}