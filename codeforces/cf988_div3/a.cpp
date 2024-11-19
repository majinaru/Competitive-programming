#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

void solve(){
    int n;
    cin >> n;

    map<int, int> freq;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        freq[a]++;
    }

    int cont = 0;
    for(auto v : freq){
        if(v.second > 1){
            cont += v.second/2;
        }
    }
    cout << cont << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
