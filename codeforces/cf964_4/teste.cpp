#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {

  map<int, int> vt;
  auto t = lower_bound(vt.begin(), vt.end(), 5);

  cout << vt.find(*t) << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
