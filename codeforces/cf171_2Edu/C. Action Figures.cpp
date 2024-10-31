#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;
  int sum = ((1 + n) * n) / 2;
  int l = 0;
  int r = 0;

  for (int i = n - 1; i >= 0; i--) {
    if (i <= l)
      break;

    if (s[i] == '1') {
      sum -= i + 1;
      l++;
    } else {
      if (l != 0)
        l--;
    }
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
