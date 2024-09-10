#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  int divB = b / 3;
  if (divB != 0) {
    int restB = b % 3;

    if (c >= restB) {
      int aux = c;
      restB += c;
      c -= aux;

      if (c == 0) {
        cout << (a + divB + 1) << endl;
        return;
      }
      int restC = c % 3;

      cout << (a + divB + 1 + c + 1) << endl;
      return;
    } else if (c + restB >= 3) {
      restB += c;
      c = 0;

      cout << (a + divB + 1) << endl;
      return;
    } else {
      cout << -1 << endl;
      return;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
