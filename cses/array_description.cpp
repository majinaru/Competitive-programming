#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> vt(n);
    vector<int> dp(m, vector<int>(n));

    for(int i = 0; i < n; i++){
        cin >> vt[i];
    }

    dp[0] = 1;
    for(int i = 1; i < n; i++){
        if(vt[i] == 0){

        }
        else{
            dp[vt[i]][i] = dp[vt[i]][i];
        }
    }


}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
