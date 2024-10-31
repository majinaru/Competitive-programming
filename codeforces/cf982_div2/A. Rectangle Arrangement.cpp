#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> vt(101);
  int maxH = 0;

  for (int i = 0; i < n; i++) {
    int w, h;
    cin >> w >> h;

    vt[h] = max(vt[h], w);
    maxH = max(maxH, h);
  }

  int sum = vt[maxH] + 2;
  for (int i = maxH - 1; i > 0; i--) {
    if (vt[i] == 0 or vt[i] == vt[i + 1]) {
      vt[i] = vt[i + 1];
      sum += 2;
      continue;
    }

    if (vt[i] > vt[i + 1]) {
      sum += (vt[i] - vt[i + 1]) * 2 + 1;
    } else if (vt[i] < vt[i + 1]) {
      sum += abs(vt[i] - vt[i + 1]) + 2;
    }
  }
  sum += vt[1];

  cout << sum << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
