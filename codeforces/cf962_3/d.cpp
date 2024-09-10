#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;

  int cont = 0;

  for (int a = 1; a <= n; a++) {
    for (int b = 1; b <= n; b++) {
      for (int c = 1; c <= n; c++) {
        if ((a * b + a * c + b * c) <= n && (a + b + c) <= x) {
          cont++;
        }
      }
    }
  }
  cout << cont << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
