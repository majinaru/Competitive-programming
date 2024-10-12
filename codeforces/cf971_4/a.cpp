#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve() {
  int a, b;
  cin >> a >> b;

  int l = a, r = b;
  int min = 1e9;

  while (l < r) {
    int c = (l + r) / 2;

    if (c - a + b - c < min) {
      min = c - a + b - c;
      r--;
    } else {
      l++;
    }
  }

  cout << ((min == 1000000000) ? 0 : min) << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
