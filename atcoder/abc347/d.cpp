#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, C;
  cin >> a >> b >> C;

  int limite = pow(2, 60);
  vector<int> at, bt;
  for (int i = 0; i < limite; i++) {
    if (__builtin_popcount(i) == a) {
      at.push_back(i);
    }
    if (__builtin_popcount(i) == b) {
      bt.push_back(i);
    }
  }

  for (auto x : at) {
    for (auto y : bt) {
      if ((x | y) == C) {
        cout << x << " " << y << endl;
        cout << __builtin_popcount(x) << endl;
        cout << __builtin_popcount(y) << endl;
        cout << (x | y) << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
