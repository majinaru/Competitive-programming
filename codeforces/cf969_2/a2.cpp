#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;


int calculaImpar(int x){
    if(x%2== 0)
        return x/2;
    return (x+1)/2;
}

void solve(){
    int l, r;
    cin >> l >> r;

    cout << (calculaImpar(r) - calculaImpar(l-1))/2 << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
