#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
vector<int> vt;

bool aceito(int mid, int m, int n) {
  vt[n - 1] += mid;
  int element = vt[(n + 2) / 2 - 1];
  vt[n - 1] -= mid;

  if ((m + mid) / (n * 2) + ((m + mid) % (n * 2) == 0 ? -1 : 0) > element - 1) {
    return true;
  }
  return false;
}

void solve() {

  int n;
  cin >> n;
  int m = 0;

  vt.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> vt[i];
    m += vt[i];
  }

  sort(vt.begin(), vt.end());

  int l = 0;
  int r = 1e18 + 1;
  int res = -1;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (aceito(mid, m, n)) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ((res == 1e18 + 1) ? -1 : res) << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
