#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  int l = k - 1;
  int r = k + 1;

  if (n == 1) {
    cout << 1 << endl << 1 << endl;
    return;
  }
  if (k == n or k == 1) {
    cout << -1 << endl;
  } else if (l % 2 == 0 && r % 2 == 0) {
    cout << 3 << endl;
    cout << 1 << " " << k - 1 << " " << r + 1 << endl;
  } else {
    cout << 3 << endl;
    cout << 1 << " " << k << " " << k + 1 << endl;
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
