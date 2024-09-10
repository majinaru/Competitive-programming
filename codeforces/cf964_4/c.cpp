#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, s, m;
  cin >> n >> s >> m;
  vector<pair<int, int>> vt;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vt.push_back({a, b});
  }

  int maxn = max(vt[0].first, m - vt[n - 1].second);

  for (int i = 1; i < n; i++) {
    if (maxn < vt[i].first - vt[i - 1].second) {
      maxn = vt[i].first - vt[i - 1].second;
    }
  }

  cout << ((maxn >= s) ? "Yes" : "No") << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
