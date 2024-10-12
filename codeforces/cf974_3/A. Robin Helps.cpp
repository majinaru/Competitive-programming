#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  int robin = 0;
  int cont = 0;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    if (a[i] >= k) {
      robin += a[i];
    }
    if (a[i] == 0 && robin > 0) {
      a[i]++;
      robin--;
      cont++;
    }
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
