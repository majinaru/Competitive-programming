#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;

  int sum = 0;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    sum += a[i];
  }

  int cur = 0;
  int maxd = 0;
  for (int i = 0; i < n; i++) {
    cur = max(0LL, cur + a[i]);
    maxd = max(maxd, cur);
  }
  sum = (sum % P + P) % P; // sum está num range (0, p-1)
  maxd = maxd % P;

  int t = 1;
  for (int i = 0; i < k; i++) {
    t = t * 2 % P;
  }

  cout << (sum + maxd * t - maxd + P) % P << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
