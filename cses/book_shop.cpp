#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> prices(n+1);
    vector<int> pages(n+1);
    for(int i = 1; i <= n; i++){
        cin >> prices[i];
    }
    for(int i = 1; i  <= n; i++){
        cin >> pages[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1));

    for(int i = 1; i <= n ; i++){
        for(int j= 1; j <= x; j++){
            if(j>= prices[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-prices[i]]+ pages[i]);
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][x] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
