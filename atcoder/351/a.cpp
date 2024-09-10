#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  int n = 9;
  int m = 8;
  int soma1 = 0;
  int soma2 = 0;

  for (int i = 0; i < n; i++) {
    cin >> a;
    soma1 += a;
  }

  for (int i = 0; i < m; i++) {
    cin >> b;
    soma2 += b;
  }
  cout << abs(soma1 - soma2) + 1 << endl;
}
