#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

void solve(){
    int n, m,q;
    cin >> n >> m >> q;
    vector<int> t(m);
    int pos;

    for(int i = 0; i < m; i++){
        cin >> t[i];
    }
    cin >> pos;
    sort(t.begin(), t.end());
    int tpos = 0;

    int minx = 1e9+5;
    for(int i = 0; i < m; i++){
        int x = abs(pos- t[i]);
        if(minx > x){
            minx = x;
            tpos = i;
        }
    }
    int ans = -1;

    if(t[tpos] > pos){
        if(tpos-1 >=0)
            ans = (t[tpos] - t[tpos-1])/2;
        else
            ans = t[tpos]-1;
    }
    else{
        if(tpos+1 < m){
            ans = (t[tpos+1] - t[tpos])/2;
            /*cout << t[pos+1] << endl;*/
            /*cout << t[pos]  << endl;*/
        }
        else
            ans = (n- t[tpos]);

    }

    cout << ans << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
