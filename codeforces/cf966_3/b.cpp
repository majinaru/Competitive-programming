#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<bool> vt(n + 2, false);
  bool cond = true;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    vt[a] = true;

    if (i == 1)
      continue;

    if (vt[a - 1] == false && vt[a + 1] == false) {
      cond = false;
    }
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
