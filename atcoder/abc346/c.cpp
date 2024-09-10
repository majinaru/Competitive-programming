#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;

  long long ans;
  ans = k * (k + 1);
  ans /= 2;

  set<int> st;

  long long a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (k >= a)
      st.insert(a);
  }
  for (auto i : st) {
    ans -= i;
  }

  cout << ans << endl;
}
