#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
const int INF = 1e18 + 5;

vector<vector<pair<int, int>>> graph(26);
vector<vector<int>> V_nodo(26, vector<int>(26, INF)); // a pro a valor tal

void djikistra(int x) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, x});
  V_nodo[x][x] = 0; // a pro a

  while (!pq.empty()) {
    auto [dist, u] = pq.top();
    pq.pop();

    if (dist > V_nodo[x][u])
      continue;

    for (auto [adj_dist, adj] : graph[u]) {
      if (V_nodo[x][adj] > V_nodo[x][u] + adj_dist) {
        V_nodo[x][adj] = V_nodo[x][u] + adj_dist;
        pq.push({V_nodo[x][adj], adj});
      }
    }
  }
}

void solve() {

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      int val;
      cin >> val;

      graph[i].push_back({val, j});
    }
  }

  for (int i = 0; i < 26; i++) {
    djikistra(i);
  }

  string s;
  cin >> s;
  int l = 0;
  int r = s.size() - 1;
  int res = 0;

  while (l < r) {
    if (s[l] == s[r]) {
      l++;
      r--;
      continue;
    }

    int L_val = s[l] - 'a';
    int R_val = s[r] - 'a';

    int minx = min(V_nodo[L_val][R_val], V_nodo[R_val][L_val]);

    for (int i = 0; i < 26; i++) {
      minx = min(minx, V_nodo[L_val][i] + V_nodo[R_val][i]);
    }

    l++;
    r--;

    res += minx;
  }
  cout << res << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
