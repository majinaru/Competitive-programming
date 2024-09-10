#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    vector<int> vt(n);
    for(int i = 0;i < n; i++){
        cin >> vt[i];
    }

    sort(vt.begin(), vt.end());
    int mid = vt[n/2 + n %2 -1]; 
    int sum = 0;

     for(int i = 0; i < n; i++){
         sum+= abs(vt[i] - mid);
     }
     cout << sum << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
