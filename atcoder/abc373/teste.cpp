#include <bits/stdc++.h>
using namespace std;

int main() {
  int res = 0;
  int last = 0;
  for (int i = 0; i < 26; i++) {
    int a;
    cin >> a;
    res += abs(a - last);
    last = a;
  }
  cout << res;
}
