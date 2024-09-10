#include <bits/stdc++.h>
using namespace std;
const int maxn = 10e6;

void solve() {
  int n, q;
  cin >> n >> q;
  string s1, s2;
  cin >> s1 >> s2;

  vector<vector<int>> prev(26, vector<int>(n + 1));
  vector<vector<int>> prev2(26, vector<int>(n + 1));

  // pre pross
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j <= n; j++) {
      int cont1 = 0;
      int cont2 = 0;
      if (s1[j - 1] - 'a' == i) {
        cont1++;
      }
      if (s2[j - 1] - 'a' == i) {
        cont2++;
      }
      prev[i][j] += prev[i][j - 1] + cont1;
      prev2[i][j] += prev2[i][j - 1] + cont2;
    }
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;

    int ans = 0;
    for (int j = 0; j < 26; j++) {
      int diff1 = prev[j][r] - prev[j][l - 1];
      int diff2 = prev2[j][r] - prev2[j][l - 1];
      ans += abs(diff2 - diff1);
    }

    cout << ans / 2 << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
