#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int soma = 0;

  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;

    soma += a;
  }

  cout << 0 - soma << endl;
}
