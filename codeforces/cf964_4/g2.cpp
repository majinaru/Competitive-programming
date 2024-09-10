#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int ans, perguntas = 0;

int pergunta(int x, int y) {
  int res = 1;
  cout << "? " << x << " " << y << endl;
  cin >> res;
  // res = 1;
  // res *= (x >= ans ? x + 1 : x);
  // res *= (y >= ans ? y + 1 : y);
  return res;
}

void solve() {
  int x = 997 / 3;
  int y = 997 / 3 + x;
  int L = 2, R = 999;
  perguntas = 0;

  while (R - L + 1 > 2) {
    int res = pergunta(x, y);

    if (res == (x + 1) * (y + 1)) {
      R = x;
    } else if (res == x * (y + 1)) {
      L = x + 1;
      R = y;
    } else {
      L = y + 1;
    }
    int terco = max(1, (R - L) / 3);
    x = L + terco;
    y = R - terco;
  }

  if (R != L) {
    int res = pergunta(L, R);
    if (res == L * (R + 1)) {
      L = R;
    } else {
      R = L;
    }
  }

  cout << "! " << L << endl;
}

int32_t main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
