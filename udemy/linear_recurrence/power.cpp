#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int powr(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
    }
    a *= a;
    b /= 2; //  b /= 2 (left shift)
  }
  return res;
}

int main() {

  cout << powr(2, 4) << endl;
  cout << (2 << 4) / 2 << endl;
  return 0;
}
