#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> vt(n);
  vt.clear();

  bool cond = true;
  for (int i = 0; i < n; i++) {
    cin >> vt[i];

    if (i > 0) {
      if (abs(vt[i] - vt[i - 1]) != 5 && abs(vt[i] - vt[i - 1]) != 7) {
        cond = false;
      }
    }
  }

  if (cond) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
