#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
const int MOD = 1e9+7;

void solve() {
    int n, x; 
    cin >> n >> x;
    vector<int> coins(n);

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<int> dp(x+1);
    dp[0] = 1;

    for(auto c: coins){
        for(int i = 1; i <=x; i++){
            if(i-c>= 0){
                (dp[i]+= dp[i-c]) %= MOD;
            }
        }
    }


    cout << dp[x] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
