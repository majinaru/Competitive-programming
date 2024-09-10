#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
using ll = long long;

void solve(){
    int n;
    cin>> n;

    vector<int> vt(n);

    for(int i = 0; i < n; i++){
        cin >> vt[i];
    }

    if(n >2){
        cout << "NO" << endl;
        return;
    }

    cout << ((vt[1] - vt[0] > 1) ? "YES" : "NO") << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}