#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const int INF = 1e9;

void solve() {
  int n;
  cin >> n;
  int maxn = 0, minx = INF;
  int sum = 0;
  vector<int> vt(n);
  for (int i = 0; i < n; i++) {
    cin >> vt[i];

    maxn = max(maxn, vt[i]);
    minx = min(minx, vt[i]);
  }

  for (int i = 1; i < n; i++) {
    sum += maxn - minx;
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
