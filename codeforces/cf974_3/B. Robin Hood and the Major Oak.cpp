#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int ll
using ll = long long;
const int MOD = 1e18;

void solve() {
  int n, k;
  cin >> n >> k;
  int sum = 0;

  int init = n - k + 1;
  int end = n;

  if ((k * (2 * n - k + 1)) / 2 % 2 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
