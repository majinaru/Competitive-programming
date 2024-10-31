#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  string s;
  string t;
  cin >> s >> t;

  int minx = min(s.size(), t.size());
  int maxn = max(s.size(), t.size());
  bool cond = true;
  int sum = 0;
  for (int i = 0; i < minx; i++) {
    if (cond) {
      if (s[i] == t[i]) {
        sum++;
      } else {
        if (i != 0)
          sum++; // copia
        cond = false;
        sum += minx - i;
        sum += maxn - i;
        break;
      }
    }
  }
  int diff = maxn - minx;
  if (cond) {
    sum++; // copia
    sum += diff;
  }
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
