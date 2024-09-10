#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
using ll = long long;

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  map<int, int> mp;

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;

    mp.insert({m, i});
  }

  cout << mp.size() << endl;
}
