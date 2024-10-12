#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
  int n;
  cin >> n;
  vector<int> vt(n);
  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  for (int i = 0; i < n - 2; i++) {
    vt[n - 2] -= vt[i];
  }

  cout << vt[n - 1] - vt[n - 2] << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
