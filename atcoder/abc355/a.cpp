#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (a == b) {
    cout << -1 << endl;
    return 0;
  }

  if (min(a, b) == 1 && max(a, b) == 2) {
    cout << a + b << endl;
  } else {
    cout << abs(a - b) << endl;
  }
}
