#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const int INF = 1e9+5;

void solve(){
    int n;
    cin >> n;

    vector<int> vt(n);
    for(int i = 0; i < n; i++){
        cin >> vt[i];
    }

    sort(vt.begin(), vt.end());

    int res = INF;
    for(int i = 0; i < n-2; i++){
        int x = lower_bound(vt.begin()+i , vt.end(), vt[i] + vt[i+1]) - vt.begin();

        res = min(res, n-x + i);
    }


    cout << res  << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
