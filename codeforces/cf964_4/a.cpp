#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  string n;
  cin >> n;

  cout << n[0] - '0' + n[1] - '0' << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
