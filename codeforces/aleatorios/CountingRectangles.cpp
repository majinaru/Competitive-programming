#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int ll
using ll = long long;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>> mat(1005 , vector<int> (1005,0));
    vector<vector<int>> pref(1005, vector<int> (1005, 0));

    for(int i = 0; i < n; i++){
        int h, w;
        cin >> h >> w;

        mat[h][w] += h*w;
    }

    // prefix
    for(int i = 1; i < 1001; i++){
        for(int j = 1; j < 1001; j++){
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i][j];
        }
    }

    while(q--){
        int hs, ws;
        cin >> hs >> ws;
        int hb, wb;
        cin >> hb >> wb;

        cout << pref[hb-1][wb-1] - pref[hb-1][ws] - pref[hs][wb-1] + pref[hs][ws] << endl;

    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
