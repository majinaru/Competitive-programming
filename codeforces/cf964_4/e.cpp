#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int maxn = 2e5 + 5;

vector<int> nums(maxn);
vector<int> prevs(maxn);

int log3(int x) {
  int cont = 0;
  while (x) {
    x /= 3;
    cont++;
  }

  return cont;
}

void solve() {
  int l, r;
  cin >> l >> r;

  int ans = nums[l] * 2;
  ans += prevs[r] - prevs[l];

  cout << ans << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  for (int i = 0; i < maxn; i++) {
    nums[i] = log3(i);
  }

  prevs[0] = 0;
  for (int i = 1; i < maxn; i++) {
    prevs[i] = prevs[i - 1] + nums[i];
  }

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
