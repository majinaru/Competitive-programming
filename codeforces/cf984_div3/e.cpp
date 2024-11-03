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

    bool cond = true;
    int L = INT_MIN;
    int R = INT_MAX;

    while (m--) {
      int r, o;
      char op;

      cin >> r >> op >> o;
      r--;

      if (op == '>') {
        int pos = upper_bound(regiao[r].begin(), regiao[r].end(), o) -
                  regiao[r].begin();

        if (pos == n) {
          // nenhum numero válido
          cond = false;
        } else {
          // guardar os paises validos (posicoes a partir de pos)
          L = max(L, pos);
        }
      } else if (op == '<') {
        int pos = upper_bound(regiao[r].begin(), regiao[r].end(), o) -
                  regiao[r].begin();
        if (pos == 0) {
          // nenhum valor válido
          cond = false;
        } else {
          // guardar os paises validos (posicoes abaixo de pos)
          R = min(R, pos - 1);
        }
      }
    }

    // Checar a condição final
    if (cond && L <= R) {
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
