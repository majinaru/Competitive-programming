#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

void solve() {
  int n, k, q;
  cin >> n >> k >> q;

  vector<int> degrees(n);
  vector<int> res(n + 1, 0);
  int num = 0;

  for (int i = 0; i < n; i++) {
    cin >> degrees[i];
    if (degrees[i] <= q) {
      num++;
      res[i] = 1;
    }
  }

  int cont = 0;
  int sum = 0;

  for (int i = 0; i <= n; i++) {
    if (res[i] == 0) {
      if (cont != 0) {
        if (cont >= k)
          sum += ((cont - k + 1) * (cont - k + 2)) / 2;
      }
      cont = 0;
    } else {
      cont++;
    }
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
