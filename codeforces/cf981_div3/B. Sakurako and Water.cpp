#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;

  map<int, int> mp;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int v;
      cin >> v;

      if (v < 0) {
        mp[i - j] = max(mp[i - j], -v);
      }
    }
  }
  int sum = 0;
  for (auto v : mp) {
    sum += v.second;
  }
  cout << sum << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
