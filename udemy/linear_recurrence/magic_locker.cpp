#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int eleva(int num) {
  int res = 1;
  int a = 3;
  while (num) {
    if (num & 1) {
      res *= a % mod;
    }
    a *= a % mod;
    num /= 2;
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  ll num = n / 3;
  ll res = n % 3;

  num = eleva(num);

  if (res == 1) {
    num--;
    num += eleva(4);
  }
  if (res == 2) {
    num += eleva(2);
  }

  cout << num << endl;

  return 0;
}
