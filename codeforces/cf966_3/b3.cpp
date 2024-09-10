#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int long long

void solve() {
  int n;
  cin >> n;

  vector<int> vt(n + 1, 0);
  bool cond = true;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    vt[a] = 1;

    if (i == 0)
      continue;

    if (vt[a - 1] == 0 && vt[a + 1] == 0) {
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
