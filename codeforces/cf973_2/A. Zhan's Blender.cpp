#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int x, y;
  cin >> x >> y;

  int res = n / min(x, y) + (n % min(x, y) == 0 ? 0 : 1);
  cout << res << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
