#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
const int INF = 1e9+5;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >>x;

    vector<int> coin(n);
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }
    vector<int> dp(x+1, INF);

    dp[0] = 0;
    for(int i = 1;i <= x; i++){
        for(auto c : coin){
            if(i-c>=0)
                dp[i] = min(dp[i], dp[i-c]+1);
        }
    }
    cout << dp[x] << endl;
            
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
