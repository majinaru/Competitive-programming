#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
const int mod = 1e9 + 7;

int mull(int a, int b) { return (int)((ll)a * b % mod); }

int powB(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mull(res, a);
    }
    a = mull(a, a);
    b /= 2;
  }

  return res;
}

void solve() {
  int a, b;
  cin >> a >> b;

  cout << powB(a, b) << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
