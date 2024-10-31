#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  // uma das piores questoes que ja fiz na vida
  int n;
  cin >> n;
  vector<int> vt(n);
  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  int cont = 0;
  for (int i = 1; i < n / 2; i++) {
    if (vt[i] == vt[i - 1] or vt[n - i] == vt[n - i - 1]) {
      swap(vt[i], vt[n - i - 1]);
    }
  }

  for (int i = 1; i < n; i++) {
    if (vt[i] == vt[i - 1])
      cont++;
  }

  cout << cont << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
