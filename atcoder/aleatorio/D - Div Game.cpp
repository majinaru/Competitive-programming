#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
  int n;
  cin >> n;

  int aux = n;
  int count = 0;
  map<int, int> mp;

  for (int i = 2; i * i <= aux; i++) {
    while (n % i == 0) {
      n /= i;
      mp[i]++;
    }
  }
  if (n > 1)
    count++;

  n = aux;

  for (auto v : mp) {
    int idx = v.first;
    int expo = v.second;
    int e = 1;
    int p = idx;

    while (expo >= e && n >= p) {
      n /= p;
      expo -= e;
      count++;
      e++;
      p *= idx;
    }
  }

  cout << count << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
