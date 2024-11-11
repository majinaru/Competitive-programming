#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

int p;

int xorn(int n){
    if(n % 4 ==0){
        return n;
    }
    if(n% 4 ==1){
        return 1;
    }
    if(n%4 ==2){
        return n+1;
    }
    if(n % 4 == 3){
        return 0;
    }
}


int prefx(int qtd, int k){
    if(qtd % 2 == 1){
        return k;
    }
    return 0;
}

int sufixo(int x, int k, int i){
    int num = (x >> i);
    int sufx = (num << i);

    cout << "x " << x << endl;
    cout << "sufx " << sufx << endl;

    if(sufx + k <= x){
        cout << "num " << num+1 << endl;
        cout << "prefx " << prefx(num+1, k);
        return ( xorn(num+1) << i ) ^ prefx(num+1, k) << endl;
    }
    else{
        cout << "num " << num << endl;
        cout << "prefx " << prefx(num, k) << endl;
        return (xorn(num) << i ) ^ prefx(num,k);
    }
}

void solve(){
    int l, r, i,k;
    cin >> l >> r >> i >> k;

    int total = xorn(r) ^ xorn(l-1);
    cout <<" total " << total << endl;
    int s = sufixo(r, k,i) ^ sufixo(l-1, k, i);
    cout << "s " << s  << endl;

    cout << (total ^ s) << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
