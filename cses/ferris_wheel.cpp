#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int L = 0, R = n-1;
    int cont = 0;
    while(L<=R){
        if(a[L] + a[R] <= x){
            cont++;
            L++;
            R--;
        }
        else if(a[R] <=x){
            cont++;
            R--;
        }
    }

    cout << cont << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
