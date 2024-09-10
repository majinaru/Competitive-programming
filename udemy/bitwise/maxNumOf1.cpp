#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
  int contmax = -1;
  int count1 = 0;
  while (n > 0) {
    if ((n & 1) == 1) {
      count1++;
      contmax = max(contmax, count1);
    } else {
      count1 = 0;
    }

    n = n >> 1;
  }
  return contmax;
}

int main() {
  int n = 156;
  cout << solve(n) << endl;
}
