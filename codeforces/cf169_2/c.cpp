#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
using ll = long long;
#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> vt(n+1);
    for(int i = 1; i <= n; i++){
        cin>> vt[i];
    }

    sort(vt.begin() +1, vt.end(), greater<int>());

    int sum=0;
    int aux = 0;
     
    for(int i = 1; i <= n;i++){
        if(i % 2 != 0){
            sum+= vt[i];
        }
        else{
            aux= min(vt[i-1] - vt[i], k);
            vt[i]+= aux;
            k-= aux;
            sum-= vt[i];
        }
    }
    cout << sum << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}
