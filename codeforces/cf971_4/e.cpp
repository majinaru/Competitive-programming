#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define endl '\n'

int n, k;

int pa(int n){
    return ((1+n)*n)/2;
}

bool valido(int index){
    if(pa(index) - pa(k-1) >= (pa(n+k-1) - pa(index)))
        return true;
    return false;
}

void solve(){
    cin >> n >> k;

    int l = k; 
    int r = k+n-1;
    //cout << l << " " << r << endl;
    int index = 0;
    int res;

    while(l<=r){
        index = (l+r)/2;

        if(valido(index)){
            r= index-1;
            res = index;
        }
        else{
            l = index+1;
        }
    }
    l = res;

    //cout << res << endl;


    int direita = abs(pa(l) - pa(k-1) - (pa(n+k-1) - pa(l)));
    int esquerda = 1e18;
    if(l>k)
        esquerda = abs(pa(l-1) - pa(k-1) - (pa(n+k-1) - pa(l-1)));

    cout << min(direita, esquerda) << endl; 
}


int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
