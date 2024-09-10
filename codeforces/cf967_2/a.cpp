#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    int maxn= 0;

    for(int i= 0; i < n; i++){
        int x;
        cin >> x;

        a[x]++;
        maxn = max(a[x], maxn);
    }

    int sum = 0;
    for(int i = 1; i <= n ;i++){
        if(a[i] == maxn){
            maxn = -1;
            continue;
        }
        sum+= a[i];
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
