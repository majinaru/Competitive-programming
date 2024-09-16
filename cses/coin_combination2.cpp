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
    dp[0] = 0;

    bool first = true;
    for(int i = 1; i <= x; i++){
        first = true;
        int cont = 0;
        for(int j = cont; j < n; j++){
            if(i-coins[j]>= 0){
                dp[i] = (dp[i] + dp[i-coins[j]]) % MOD;
                if(first){
                    cont++;
                    first = false;
                }
            }
        }
    }
    cout << dp[x] << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
