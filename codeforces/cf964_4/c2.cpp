#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, m, s;
  cin >> n >> m >> s;
  vector<int> entrada(n);
  vector<int> saida(n);

  for (int i = 0; i < n; i++) {
    cin >> entrada[i] >> saida[i];
  }

  sort(entrada.begin(), entrada.end());
  sort(saida.begin(), saida.end());

  int cont = 0, maxn = 0;
  for (int i = 0; i <= s; i++) {
    auto t = lower_bound(entrada.begin(), entrada.end(), i) - entrada.begin();

    if (t > s) {
      continue;
    }

    if (entrada[t] > i) {
      cont++;
    } else if (saida[t] > i) {
      cont = 0;
    }

    if (cont > maxn) {
      maxn = cont;
    }
  }

  cout << ((maxn >= m) ? "Yes" : "No") << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
