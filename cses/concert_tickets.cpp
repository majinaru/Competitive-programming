#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
const int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> tickets(n);
    vector<int> costumers(m);
    set<pair<int,int>> sortedTickets;

    for(int i = 0; i < n; i++){
        cin >> tickets[i];
        sortedTickets.insert({tickets[i], i});
    }

    for(int i = 0; i < m; i++){
        cin >> costumers[i];
    }

    for(int i = 0; i < m; i++){
        auto match = sortedTickets.lower_bound({costumers[i] +1, 0});

        if(match == sortedTickets.begin()){
            cout << -1 << endl;
        }
        else{
            match--;
            cout << (*match).first << endl;
            sortedTickets.erase(match);
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
