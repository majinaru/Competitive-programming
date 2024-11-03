#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve() {
  int n;
  cin >> n;
  int maxH = 0, maxW = 0;
  for (int i = 0; i < n; i++) {
    int w, h;
    cin >> w >> h;

    maxH = max(maxH, h);
    maxW = max(maxW, w);
  }

  cout << 2 * maxH + 2 * maxW << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
