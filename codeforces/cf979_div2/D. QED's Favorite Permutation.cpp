#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> vt(n);
  vector<int> pref(n);
  int maxn = 0;
  for (int i = 0; i < n; i++) {
    cin >> vt[i];

    maxn = max(maxn, vt[i]);
    pref[i] = maxn;
  }

  string s;
  cin >> s;
  int cont = 0;

  for (int i = 1; i < s.size() - 1; i++) {
    if (s[i] == 'L' && s[i + 1] == 'R') {
      if (pref[i] > i + 1) {
        cont++;
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int v;
    cin >> v;
    v--;

    // apagar antigo
    if (s[v] == 'L' && s[v + 1] == 'R' && pref[v] > v + 1) {
      cont--;
    }

    if (s[v - 1] == 'L' && s[v] == 'R' && pref[v - 1] > v) {
      cont--;
    }

    // troca
    if (s[v] == 'L') {
      s[v] = 'R';
    } else {
      s[v] = 'L';
    }

    // adiciona
    if (s[v] == 'L' && s[v + 1] == 'R' && pref[v] > v + 1) {
      cont++;
    }

    if (s[v - 1] == 'L' && s[v] == 'R' && pref[v - 1] > v) {
      cont++;
    }

    if (cont <= 0)
      cout << "YES" << endl;
    else {
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
