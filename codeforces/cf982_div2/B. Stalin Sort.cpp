#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int INF = 1e9 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> vt(n);

  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  int minx = INF;
  for (int i = 0; i < n; i++) {
    int maxn = 0;
    for (int j = i; j < n; j++) {
      if (vt[i] < vt[j]) {
        maxn++;
      }
    }
    minx = min(minx, maxn + i);
  }
  cout << minx << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
