#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> row(n), col(n);
  int r, c;
  bool cond = true;
  int d1, d2;
  d1 = d2 = 0;

  for (int i = 0; i < t; i++) {
    int a;
    cin >> a;
    if (cond) {
      r = (a - 1) / n;
      c = (a - 1) % n;

      row[r]++;
      col[c]++;
      if (c == r) {
        d1++;
      }
      if (r + c == n - 1) {
        d2++;
      }
      if (row[r] == n || col[c] == n || d1 == n || d2 == n) {
        cout << i + 1 << endl;
        cond = false;
      }
    }
  }
  if (cond) {
    cout << -1 << endl;
  }
}
