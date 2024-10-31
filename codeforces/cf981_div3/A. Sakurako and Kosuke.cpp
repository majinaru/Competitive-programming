#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;

  int x = 0;
  bool s = true;
  int ind = 1;

  while (x <= n && x >= -n) {
    if (s) {
      x += -ind;

      s = false;
    } else {
      x += ind;
      s = true;
    }
    ind += 2;
  }
  if (s) {
    cout << "Kosuke" << endl;
  } else {
    cout << "Sakurako" << endl;
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
