#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
const int MOD = 1e9+7;
const int inf = 0;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 1));

    for(int i = 0; i < n; i++){
        for(int j=0; j < n; j++){
            char x;
            cin >> x;
            if(x=='*')
                grid[i][j] = 0;
        }
    }

    for(int i = 1; i < n; i++){
        grid[i][0] &= grid[i-1][0];
        grid[0][i] &= grid[0][i-1];
    }


    for(int i = 1; i < n; i++){
        for(int j = 1; j< n; j++){
            if(grid[i][j] != 0){
                grid[i][j] = (grid[i-1][j] + grid[i][j-1]) % MOD;
            }
        }
    }

    cout << grid[n-1][n-1] << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
