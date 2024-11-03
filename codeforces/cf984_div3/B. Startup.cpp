#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  map<int, int> prat;

  for (int i = 0; i < k; i++) {
    int b, c;
    cin >> b >> c;
    prat[b] += c;
  }

  vector<int> vt;
  for (auto v : prat) {
    vt.push_back(v.second);
  }

  sort(vt.begin(), vt.end(), greater<>());

  int cont = 0;
  int sum = 0;
  for (int i = 0; i < vt.size(); i++) {
    if (cont < n) {
      sum += vt[i];
    }
    cont++;
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
