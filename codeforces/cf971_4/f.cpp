#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define int ll

    vector<int> a;
    vector<int> pref;
    vector<int> t;
    vector<int> pref_t;
    int n, q;

int calculo(int x){
    int pos = (x/n+ x % n) % n; 
    int res = 0;
    res = (x/n * pref[n]); 

    int index_a2 = pos + n;
    res+= pref_t[index_a2 + 1] - pref_t[index_a2  - x % n];
    
    return res;
}


void solve(){
    cin >> n >> q;
    a.resize(n);
    t.resize(n*2);
    pref.resize(n+1);
    pref_t.resize(n*2 + 1);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i= 0; i < n*2; i++){
        t[i] = a[i%n];
    }

    pref_t[0] = 0;
    for(int i = 1; i <= n*2; i++){
        pref_t[i] = pref_t[i-1]+ t[i-1];
    }

    pref[0] = 0; 
    for(int i = 1; i <= n;  i++){
        pref[i] = pref[i-1] + a[i-1];
    }

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;

        cout << calculo(r) -   ((l == 0) ? 0 : calculo(l-1)) << endl;
    }

}


int32_t main(){
    /*cin.tie(0)->sync_with_stdio(0);*/
    int t; 
    cin >> t;
    while(t--){
        solve();
    }
}
