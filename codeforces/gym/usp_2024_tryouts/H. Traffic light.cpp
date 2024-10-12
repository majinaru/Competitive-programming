#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
const int INF = 1e18 + 5;

struct Edge {
  int v, op, close;
};

vector<vector<Edge>> graph(1e5 + 2);
vector<int> dist;
int t;

void djikstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  dist[0] = t;
  pq.push({t, 0}); // dist nodo

  while (!pq.empty()) {
    auto [dist_origem, nodo_origem] = pq.top();
    pq.pop();

    if (dist_origem > dist[nodo_origem]) {
      continue;
    }

    for (auto [nodo_adj, op, close] : graph[nodo_origem]) {
      int wait;

      if (dist[nodo_origem] % (close + op) < op) {
        wait = 0;
      } else {
        wait = abs((op + close) - (dist[nodo_origem] % (op + close)));
      }
      int x = dist[nodo_origem] + wait;

      if (dist[nodo_adj] > x) {
        dist[nodo_adj] = x;
        pq.push({dist[nodo_adj], nodo_adj});
      }
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m >> t;

  dist.assign(n, INF);

  for (int i = 0; i < m; i++) {
    int a, b, x, y;

    cin >> a >> b >> x >> y;

    a--;
    b--;
    graph[a].push_back({b, x, y});
    graph[b].push_back({a, x, y});
  }

  djikstra();

  cout << dist[n - 1] << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
