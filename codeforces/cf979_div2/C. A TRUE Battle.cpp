#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  bool cond = false;

  if (s[0] == '1' || s[n - 1] == '1') {
    cond = true;
  }

  int cont = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cont = 0;
    } else {
      cont++;
    }
    if (cont > 1)
      cond = true;
  }
  cout << (cond ? "YES" : "NO") << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
