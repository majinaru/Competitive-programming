#include <bits/stdc++.h>
#include <numeric>
using namespace std;

const int MAXN = 1e6;

int32_t main() {
  vector<int> max_divs(MAXN + 1, 0);
  max_divs[0] = max_divs[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (max_divs[i] == 0)
      for (int j = i; j <= MAXN; j += i) {
        max_divs[j] = i;
      }
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int div_num = 1;
    while (x != 1) {
      int prime = max_divs[x];
      int count = 0;
      while (x % prime == 0) {
        count++;
        x /= prime;
      }
      div_num *= count + 1;
    }
    cout << div_num << endl;
  }
}
