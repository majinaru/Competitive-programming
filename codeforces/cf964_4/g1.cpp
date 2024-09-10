#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int x = 1;
  int L = 2;
  int R = 999;

  while (L <= R) {
    int res;
    int y = (L + R) / 2;

    cout << "? " << x << " " << y << endl;
    cin >> res;

    if (res > y) {
      R = y - 1;
    } else {
      L = y + 1;
    }
  }
  cout << "! " << L << endl;
}

int32_t main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
