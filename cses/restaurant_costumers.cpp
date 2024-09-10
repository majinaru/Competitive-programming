#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> events;

    for(int i = 0; i < n; i++){
        int e, s;
        cin>> e >> s;
        events.push_back({e,1});
        events.push_back({s, -1});
    }
    sort(events.begin(), events.end());

    int sum = 0;
    int maxn = 0;
    for(int i = 0; i< n*2; i++){
        sum+= events[i].second;
        maxn = max(maxn, sum);
    }
    cout << maxn << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
