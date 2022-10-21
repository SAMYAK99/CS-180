//check whether its a valid ISBN or not

#include <bits/stdc++.h>
using namespace std;
bool isvalid(string &isbn_number) {
   int n = isbn_number.length();
   if (n != 10)
      return false;
   int sum = 0;
   for (int i = 0; i < 9; i++) {
      int value = isbn_number[i] - '0';
      if (0 > value || 9 < value)
         return false;
      sum += (value * (10 - i));
   }
   char last_val = isbn_number[9];
   if (last_val != 'X' && (last_val < '0' || last_val > '9'))
      return false;
   sum += ((last_val == 'X') ? 10 : (last_val - '0'));
   return (sum % 11 == 0);
}
int main() {
   string isbn_number = "002442142X";
   if (isvalid(isbn_number))
      cout<<isbn_number<<" is Valid";
   else
      cout<<isbn_number<<" is invalid";
   return 0;
}

