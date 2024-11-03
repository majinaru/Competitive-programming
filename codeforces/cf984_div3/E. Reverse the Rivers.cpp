#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<vector<int>> regiao(k, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int val;
      cin >> val;

      if (i == 0) {
        regiao[j][i] = val;
      } else {
        regiao[j][i] = val | regiao[j][i - 1];
      }
    }
  }

  while (q--) {
    int m;
    cin >> m;

    int L = 0;
    int R = n - 1;

    while (m--) {
      int r;
      char op;
      int o;

      cin >> r >> op >> o;
      r--;
      if (op == '>') {
        int pos = upper_bound(regiao[r].begin(), regiao[r].end(), o) -
                  regiao[r].begin();
        L = max(L, pos);
      } else if (op == '<') {
        int pos = lower_bound(regiao[r].begin(), regiao[r].end(), o) -
                  regiao[r].begin();
        R = min(R, pos - 1);
      }
    }

    if (L <= R && L < n) {
      cout << L + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
