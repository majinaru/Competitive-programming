#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
const int MOD = 1e9 + 7;

int mull(int a, int b, int m) { return (a * b) % m; }

int powB(int a, int b, int m) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mull(res, a, m);
    }
    a = mull(a, a, m);
    b /= 2;
  }
  return res;
}

int phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      result -= result / i;
    }
  }
  if (n > 1) {
    result -= result / n;
  }
  return result;
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  int modphi = 1e9 + 6;
  int x = powB(b, c, modphi);
  cout << powB(a, x, MOD) << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
