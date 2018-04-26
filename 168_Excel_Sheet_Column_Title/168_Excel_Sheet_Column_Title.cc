#include <iostream>
#include <unordered_map>
string convertToTitle(int n) {
   std::unordered_map <int, char> unMap = {{0, 'Z'}, {1, 'A'}, {2, 'B'}, {3, 'C'},
      {4, 'D'}, {5, 'E'}, {6, 'F'},{7, 'G'}, {8, 'H'}, {9, 'I'},{10, 'J'}, 
      {11, 'K'}, {12, 'L'},{13, 'M'}, {14, 'N'}, {15, 'O'},{16, 'P'}, {17, 'Q'}, 
      {18, 'R'},{19, 'S'}, {20, 'T'}, {21, 'U'},{22, 'V'}, {23, 'W'}, 
      {24, 'X'}, {25, 'Y'}};
    int temp = n; 
    int i = 0;
    string str = "";
    while (temp != 0) {
      i = temp % 26;
      str.insert(str.begin(), unMap[i]);
      if (i == 0) {
        temp = temp / 26 - 1;
      } else {
        temp = temp / 26;
      }
    }
    return str;
    }
