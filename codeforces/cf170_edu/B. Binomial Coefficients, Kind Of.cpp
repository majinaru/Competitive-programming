#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int MOD = 1e9 + 7;

int powB(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b /= 2;
  }
  return res;
}

void solve() {

  int t;
  cin >> t;

  vector<int> n(t);
  vector<int> k(t);

  for (int i = 0; i < t; i++) {
    cin >> n[i];
  }
  for (int i = 0; i < t; i++) {
    cin >> k[i];
    cout << powB(2, k[i]) << endl;
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
