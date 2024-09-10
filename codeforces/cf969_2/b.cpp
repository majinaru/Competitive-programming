#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> vt(n);

    int maxn = 0;
    for(int i = 0; i < n; i++){
        cin >> vt[i];
        maxn = max(maxn, vt[i]);
    }

    for(int i = 0; i < m; i++){
        char op;
        int l, r;
        cin >> op >> l >> r;

        if(op == '+' && r>= maxn && l<= maxn){
            maxn++;
        }
        else if(r >= maxn && l<= maxn){
            maxn--;
        }
        cout << maxn << " ";
    }
    cout << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}
