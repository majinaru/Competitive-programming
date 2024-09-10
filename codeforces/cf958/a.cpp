#include <bits/stdc++.h>
using namespace std;

void func() {
  int n, k;
  cin >> n >> k;
  cout << ceil((float)(n - 1) / (float)(k - 1)) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    func();
  }
}
