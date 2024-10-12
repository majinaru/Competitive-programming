#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define endl '\n'
using ll = long long;

void sufixo(string &t, int n) {
  while (t.size() < n) {
    bool b;

    cout << "? " << to_string(0) + t << endl;
    cin >> b;

    if (b) {
      t = to_string(0) + t;
      continue;
    } else {
      t = to_string(1) + t;
    }
  }
}

void solve() {
  int n;
  cin >> n;

  string t = "";

  while (t.size() < n) {
    bool b;

    cout << "? " << t + to_string(0) << endl;
    cin >> b;

    if (b) {
      t += to_string(0);
      continue;
    } else {
      cout << "? " << t + to_string(1) << endl;
      cin >> b;
    }

    if (b) {
      t += to_string(1);
      continue;
    } else {
      // sufixo
      sufixo(t, n);
    }
  }
  cout << "! " << t << endl;
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
