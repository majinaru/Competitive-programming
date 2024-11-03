#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
const int INF = 1e18;

void solve() {
  int n;
  cin >> n;
  int ones = 0;
  int zeros = 0;

  for (int i = 0; i < 2 * n; i++) {
    int a;
    cin >> a;

    if (a == 0) {
      zeros++;
    } else {
      ones++;
    }
  }

  int resMax = 0;
  int resMin = INF;
  int maxn = max(ones, zeros);
  int minx = min(ones, zeros);

  resMax = minx;
  resMin = (ones % 2 + zeros % 2) / 2;

  cout << resMin << " " << resMax << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
