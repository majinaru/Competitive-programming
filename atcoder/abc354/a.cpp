#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;

  int i = 1;
  while (((1 << i) - 1) < n) {
    i++;
  }
  if (((1 << i) - 1) > n) {
    cout << i << endl;
  } else {
    cout << i + 1 << endl;
  }

  return 0;
}
