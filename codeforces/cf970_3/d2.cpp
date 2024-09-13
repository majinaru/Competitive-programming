#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
using ll = long long;

int n;
vector<int> vt;
vector<int> f;
string s;

int fun(int j){
    int atual  = ((s[j] - '0' )? 0 : 1);
    if(vt[j] == j){
        return atual;
    }

    if(f[j] == -1){
        f[j] = atual + fun(vt[j]); 
    }

    return f[j];
}


void solve(){
    cin >> n;
    vt.resize(n);
    f.resize(n, -1);

    for(int i = 0; i < n; i++){
        cin >> vt[i];
        vt[i]--;
    }

    cin >> s;

    for(int i = 0; i < n; i ++){
        cout << fun(i) << " ";
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
