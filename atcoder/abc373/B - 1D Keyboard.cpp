#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  vector<char> vt = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                     'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                     'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  string s;
  cin >> s;
  map<char, int> freq;

  for (int i = 0; i < 26; i++) {
    freq[s[i]] = i;
  }

  int last = freq['A'];
  int res = 0;
  for (int i = 0; i < 26; i++) {
    int pos = freq[vt[i]];
    res += abs(pos - last);
    last = pos;
  }
  cout << res << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
