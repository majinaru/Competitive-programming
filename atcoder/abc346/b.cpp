#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "wbwbwwbwbwbw";
  string s1 = "wbwb"; // w b= w-1   b ==w
  string s2 = "bwwbw";

  int w, b;
  cin >> w >> b;

  if (w == b + 1 || w == b) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  cout << endl;
}
