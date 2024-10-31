#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
const int INF = 1e9 + 5;

void solve() {
  int n, m;
  cin >> n >> m;

  int sum = 0;
  int cmin = INF;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int xj;
      cin >> xj;
      if ((i + j) % 2 != 0)
        cmin = min(cmin, xj);
      sum += xj;
    }
  }

  if (n % 2 != 0 or m % 2 != 0) {
    cout << sum << endl;
  } else {
    cout << sum - cmin << endl;
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
