#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> vt(n);
  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }
  sort(vt.begin(), vt.end());

  int cont = 0;
  int cont2 = 0;
  for (int i = 0; i < n - 1; i++) {
    if (vt[i] + vt[i + 1] <= vt[n - 1]) {
      cont++;
    }
  }

  int pos = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (vt[i] + vt[i + 1] <= vt[pos]) {
      cont2++;
      pos--;
    }
  }

  cout << min(cont, cont2) << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
