#include <bits/stdc++.h>
using namespace std;

vector<int> fact(int n) {
  vector<int> res;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n > 1)
    res.push_back(n);
  return res;
}

void solve() {
  int n;
  cin >> n;

  for (auto v : fact(n)) {
    cout << v << " ";
  }
  cout << endl;
}

int32_t main() { solve(); }
