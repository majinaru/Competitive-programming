#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, a, b;
  cin >> n >> a >> b;

  vector<long long> d(n);
  bool cond = true;
  for (int i = 0; i < n; i++) {
    cin >> d[i];

    if (d[i] % (a + b) > a) {
      cond = false;
    }
  }

  if (cond) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
