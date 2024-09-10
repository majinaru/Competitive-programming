#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

vector<bool> primos;
vector<int> freq;

void crivo(){
    for(int i = 2; i < 1000; i++){
        if(primos[i]){
            for(int j = i*i; j  < 1000; j+=i){
                primos[j] = false;
            }
        }
    }
}

void frequencia(){
    for(int i = 1; i < 1000; i++){
        freq[i] = freq[i-1] + ((primos[i]) ? 1 :0);
    }
}

void solve(){
    int l,r;
    cin >> l >> r;

    if(l != 0)
        cout << (freq[r] - freq[l-1]) << endl;
    else
        cout << freq[r] << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    primos.resize(1000, true);
    freq.resize(1000, 0);
    crivo();
    frequencia();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
