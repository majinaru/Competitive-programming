#include <bits/stdc++.h>
using namespace std;

int charToDigit(char ch) { return ch - '0'; }

char digitToChar(int x) { return x + '0'; }

string addNumbers(string n1, string n2) {
  // make sure n2 is larger
  if (n1.length() > n2.length()) {
    swap(n1, n2);
  }

  // result
  string result = "";

  reverse(n1.begin(), n1.end());
  reverse(n2.begin(), n2.end());

  // add digit upto a n1.length()
  int carry = 0;
  for (int i = 0; i < n1.length(); i++) {
    int d1 = charToDigit(n1[i]);
    int d2 = charToDigit(n2[i]);
    int sum = d1 + d2 + carry;
    int output_digit = sum % 10;
    carry = sum / 10;
    result.push_back(digitToChar(output_digit));
  }

  for (int i = n1.length(); i < n2.length(); i++) {
    int d2 = charToDigit(n2[i]);
    int sum = d2 + carry;
    int output_digit = sum % 10;
    carry = sum / 10;

    result.push_back(digitToChar(output_digit));
  }

  // Se carry for gerado
  if (carry) {
    result.push_back(1);
  }

  reverse(result.begin(), result.end());
  return result;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  string result = addNumbers(s1, s2);
  cout << result << endl;
}
