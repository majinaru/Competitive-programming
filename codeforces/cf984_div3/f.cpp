#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
#define int ll

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
    return 0;
}


int prefx(int qtd, int k){
    if(qtd < 0)
        return 0;
    if(qtd % 2 == 1){
        return k;
    }
    return 0;
}

int sufixo(int x, int k, int i){
    int num = (x >> i);
    int sufx = (num << i);


    if(sufx + k <= x){
        p += num+1;
        return (xorn(num));
    }
    else{
        p += num;
        return (xorn(num-1));
    }
}

void solve(int cont){
    p = 0;
    int l, r, i,k;
    cin >> l >> r >> i >> k;
    if(cont == 51){
        cout << l <<r  << i << k;
    }

    int total = xorn(r) ^ xorn(l-1);
    int s = ((sufixo(r, k,i) ^ sufixo(l-1, k, i))<< i) ^ prefx(p,k);



    if( (1 <<i) >= r && k <= r && k >= l){
        cout << (total ^ k) << endl;
    }
    else{
        cout << (total ^ s) << endl;
    }

}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    int cont = 0;
    while(t--){
        solve(cont);
    }

}
