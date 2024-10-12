#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<char> vt = {'a', 'e', 'i', 'o', 'u'};
  vector<int> freq(5);
  string ans = "";

  for (int i = 0; i < n; i++) {
    freq[i % 5]++;
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < freq[i]; j++) {
      ans += vt[i];
    }
  }
  cout << ans << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
