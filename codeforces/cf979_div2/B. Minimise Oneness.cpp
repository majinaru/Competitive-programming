#include <bits/stdc++.h>
#include <string>
using namespace std;
#define endl '\n'
using ll = long long;

string bin(int n) {
  string res;
  bool z = true;
  int m = n / 2;

  for (int i = 0; i < n; i++) {
    if (i == m && z) {
      res.push_back('1');
      z = false;
    } else {
      res.push_back('0');
    }
  }

  return res;
}

void solve() {
  int n;
  cin >> n;

  string s = bin(n);
  cout << s << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
