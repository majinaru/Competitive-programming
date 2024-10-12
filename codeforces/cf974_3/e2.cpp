#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define endl "\n"
using ll = long long;
#define int ll
const int INF = 2e18 + 5;

int n, m, h;
vector<vector<pair<int, int>>> graph;
vector<bool> horses;

void djikstra(int init, vector<int> &nodoX) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push({0, init});

  while (!pq.empty()) {
    auto [dist, origem] = pq.top();
    pq.pop();

    if (dist > nodoX[origem]) {
      continue;
    }

    for (auto [peso, adj] : graph[origem]) {
      if (nodoX[adj] > nodoX[origem] + peso) {
        nodoX[adj] = nodoX[origem] + peso;
        pq.push({nodoX[adj], adj});
      }
    }
  }
}

void solve() {
  cin >> n >> m >> h;

  graph.resize(2 * n);
  for (int i = 0; i < 2 * n; i++)
    graph[i].clear();

  horses.resize(2 * n);
  for (int i = 0; i < 2 * n; i++)
    horses[i] = false;

  vector<int> nodo1(2 * n, INF);
  vector<int> nodo2(2 * n, INF);
  nodo1[0] = 0;
  nodo2[n - 1] = 0;

  for (int i = 0; i < h; i++) {
    int a;
    cin >> a;
    a--;
    horses[a] = true;
    horses[a + n] = true;

    graph[a].push_back({0, a + n});
    graph[a + n].push_back({0, a});
  }
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    graph[a].push_back({w, b});
    graph[b].push_back({w, a});

    graph[a + n].push_back({w / 2, b + n});
    graph[b + n].push_back({w / 2, a + n});
  }

  djikstra(0, nodo1);
  djikstra(n - 1, nodo2);

  int res = INF;
  for (int i = n; i < 2 * n; i++) {
    res = min({res, max(nodo1[i - n], nodo2[i]), max(nodo1[i], nodo2[i - n]),
               max(nodo1[i - n], nodo2[i - n]), max(nodo1[i], nodo2[i])});
  }
  cout << ((res == INF) ? -1 : res) << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
