#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll = long long;

int ask(int x, int y){
    int res;
    cout << "? " << x +1<< " " << y +1<< endl;
    cin >> res;
    res--;
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> par(n,-1);

    for(int i = 1; i <n; i++){
        int last = 0;
        while(true){
            int x = ask(i, last);
            if(x == i) break;
            last = x;
        }
        par[i] = last;
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
