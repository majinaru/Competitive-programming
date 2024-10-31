#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  int Z = 0;
  int res = 0;
  bool cond = true;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    if (num == 0) {
      Z++;
      continue;
    }
    if (num > 0) { // I
      if (Z >= num) {
        Z -= num;
      } else if (cond) {
        cond = false;
      }
    }
    if (num < 0) { // S
      if (Z >= num * -1) {
        Z += num;
      } else if (cond) {
        cond = false;
      }
    }
    if (cond) {
      res++;
    }
  }
  cout << res << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
