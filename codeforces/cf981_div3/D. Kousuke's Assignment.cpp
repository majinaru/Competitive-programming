#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int INF = 1e9 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> vt(n);
  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  vector<int> pref(n);
  map<int, int> mp;
  pref[0] = vt[0];
  mp[vt[0]] = 0;
  int cont = 0;
  int last = INF;
  if (vt[0]) {
    last = 0;
    cont++;
  }

  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + vt[i];

    if (mp.count(pref[i])) {
      if (last < mp[pref[i]])
        cont++;
      last = i;
    }
    mp[pref[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cout << pref[i] << " ";
  }
  cout << endl;
  for (auto v : mp) {
    cout << v.first << " " << v.second << endl;
  }
  cout << endl;
  cout << cont << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
