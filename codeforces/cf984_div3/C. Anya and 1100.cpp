#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  int cont = 0;

  auto contar1100 = [&]() -> void {
    for (int i = 0; i + 3 < s.size(); i++) {
      if (s.substr(i, 4) == "1100") {
        cont++;
      }
    }
  };

  contar1100();

  while (q--) {
    int u;
    char v;
    cin >> u >> v;
    u--;

    if (s[u] != v) {
      for (int i = max(u - 3, 0); i <= u; i++) {
        if (i + 3 < s.size() && s.substr(i, 4) == "1100") {
          cont--;
        }
      }

      s[u] = v;

      for (int i = max(u - 3, 0); i <= u; i++) {
        if (i + 3 < s.size() && s.substr(i, 4) == "1100") {
          cont++;
        }
      }
    }

    if (cont > 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
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
