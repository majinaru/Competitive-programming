#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
const int INF = 1e9 +5;
using ll = long long;
#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> vt(n);

    for(int i = 0; i < n; i++){
        cin >> vt[i];
    }

    int past = vt[0];
    int ans = vt[0];
    for(int i = 1; i < n; i++){
        past = max(past + vt[i], vt[i]);
        ans = max(ans, past);
    }

    cout << ans << endl;


}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
