#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> vt(n);
  vector<int> pref(n);

  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  pref[0] = vt[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + vt[i];
  }

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a != 0)
      cout << pref[b] - pref[a - 1] << endl;
    else
      cout << pref[b] << endl;
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
