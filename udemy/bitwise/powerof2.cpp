#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if ((n & (n - 1)) == 0) {
    cout << "É potencia de 2" << endl;
  } else {
    cout << "Não é potência de 2 " << endl;
  }
}
