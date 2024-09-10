#include <bits/stdc++.h>
using namespace std;

int multiply(int a, int b, int c) {
  int res = 0;
  while (b) {
    if (b & 1) {
      res += a;
    }
    a += a;
    b /= 2;
  }

  return res;
}

int main() {
  cout << multiply(2, 20, 1e9 + 7) << endl;

  return 0;
}
