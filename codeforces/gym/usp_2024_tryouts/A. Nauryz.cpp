#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> zeros;
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> ones;
  vector<int> res;

  for (int i = 0; i < n; i++) {
    int t, m, c;
    cin >> t >> m >> c;

    if (c == 0)
      zeros.push({t, m + t, c, i + 1});
    else
      ones.push({t, m + t, c, i + 1});
  }

  vector<vector<int>> juncao;
  if (zeros.empty() && !ones.empty()) {
    juncao.push_back(ones.top());
    ones.pop();
  } else if (!zeros.empty() && ones.empty()) {
    juncao.push_back(zeros.top());
    zeros.pop();
  } else if (zeros.top() < ones.top()) {
    juncao.push_back(zeros.top());
    zeros.pop();
  } else {
    juncao.push_back(ones.top());
    ones.pop();
  }

  while (juncao.size() < n) {
    auto last = *juncao.rbegin();
    vector<int> cur;

    if (zeros.empty() && !ones.empty()) {
      cur = ones.top();
      ones.pop();
    } else if (ones.empty() && !zeros.empty()) {
      cur = zeros.top();
      zeros.pop();
    } else if (zeros.top() < ones.top() && ones.top()[1] > last[1]) {
      cur = zeros.top();
      zeros.pop();
    } else {
      cur = ones.top();
      ones.pop();
    }

    if (cur[0] < last[1] || cur[1] < last[1]) {
      if (cur[2] == 0) {
        int aux = cur[0];
        cur[0] = last[1];
        cur[1] = cur[0] + (cur[1] - aux);
      } else if (cur[2] == 1) {
        res.push_back(last[3]);
      }
    }
    juncao.push_back(cur);
  }

  juncao.pop_back();

  cout << res.size() << endl;
  for (auto v : res) {
    cout << v << " ";
  }
  cout << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
