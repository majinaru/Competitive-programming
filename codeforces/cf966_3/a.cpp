#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  string s;
  cin >> s;
  bool cond = true;

  if (s.size() < 3) {
    cout << "NO" << endl;
    return;
  }
  if (!(s[0] == '1' && s[1] == '0')) {
    cond = false;
  }

  string s2;
  for (int i = 2; i < s.size(); i++) {
    s2 += s[i];
  }

  int cont = 0;
  while (s2[cont] == '0') {
    cont++;
  }
  cont--;

  if (s2.size() == 1 && (s2[0] - '0' < 2)) {
    cond = false;
  }

  if (cont != -1) {
    cond = false;
  }

  cout << ((cond) ? "YES" : "NO") << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
