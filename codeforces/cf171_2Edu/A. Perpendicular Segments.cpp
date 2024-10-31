#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int x, y;
  int k;
  cin >> x >> y >> k;

  int p = min(y, x);

  cout << 0 << " " << 0 << " " << p << " " << p << endl;
  cout << 0 << " " << p << " " << p << " " << 0 << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
