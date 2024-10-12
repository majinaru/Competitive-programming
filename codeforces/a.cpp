#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  int d = 3 - b % 3;
  if (b % 3 == 0)
    d = 0;

  if (d > c) {
    cout << -1 << endl;
  } else {
    cout << a + (b + d) / 3 + (c - d + 2) / 3 << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
