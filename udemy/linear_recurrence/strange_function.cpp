#include <bits/stdc++.h>
using namespace std;

int solve(long long A, long long N) {
  long long T = A ^ N;

  long long res = 0;
  while (T) {
    if (T & 1) {
      res += T;
    }
  }
}

int main() {
  int a, n;
  cin >> a >> n;

  solve(a, n);
}
