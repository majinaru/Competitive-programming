#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n;
    cin >> n;
    set<int> st;
    vector<int> vt(n);
    for(int i = 0; i < n; i++){
        cin >> vt[i];
    }

    int maxn = -1;
    int i = 0;
    int j = 1;
    while(i < n && j < n){
        if(vt[i] == vt[j] && !st.count(vt[j])){
            st.insert(vt[j]);
            maxn = max(maxn, j-i+1);
            i++;
        }
        else{
            st.erase(vt[j]);
            j++;
        }
    }
    cout << maxn << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
