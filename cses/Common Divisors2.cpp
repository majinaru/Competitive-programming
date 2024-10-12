#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
const int lim = 1e6;

vector<int> range(1e6 + 1);

void solve() {
  int n;
  cin >> n;

  int res = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    range[x]++;
  }

  for (int i = 1; i <= lim; i++) {
    int multiples = 0;
    for (int j = i; j <= lim; j += i) {
      multiples += range[j];

      if (multiples > 1) {
        res = i;
      }
    }
  }

  cout << res << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
