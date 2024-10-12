#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  string s;
  int cont = 0;
  for (int i = 0; i < 12; i++) {
    cin >> s;
    if (s.size() == i + 1) {
      cont++;
    }
  }
  cout << cont << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
