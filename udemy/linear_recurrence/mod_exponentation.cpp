#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll powr(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      res %= mod;
    }
    a *= a;
    a %= mod;
    b /= 2; //  b /= 2 (left shift)
  }
  return res;
}

int32_t main() {

  cout << powr(2, 200) << endl;
  return 0;
}
