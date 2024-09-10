#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> pref(n+1);
    map<int,int> p;
    int cont= 0;

    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1]+ a[i];

        p[pref[i-1]+x]++;

        if(p[pref[i]]){
            cont+= p[pref[i]];
        }
    }

    cout << cont << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
