#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int t = k;
  int atracao = 0;
  queue<int> a;
  int b;

  for (int i = 0; i < n; i++) {
    cin >> b;
    a.push(b);
  }

  while (a.size() > 0) {
    if (t < a.front()) {
      atracao++;
      t = k;
    } else {
      t -= a.front();
      a.pop();
    }
  }
  cout << atracao + 1 << endl;
}
