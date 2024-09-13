#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename U>
using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    vector<int> vt(n);
    ordered_set<pair<int,int>> st;

    for(int i = 0; i < n; i++){
        cin >> vt[i];

        st.insert({vt[i], i});
    }

    sort(vt.begin(), vt.end());

    int cont = 0;

    for(int i = 0; i < n-1; i++){
        if(st.find_by_order(vt[i]-1)->second < st.find_by_order(vt[i+1]-1)->second){
            continue;
        }
        else{
            cont++;
        }
    }

    cout << cont + 1<< endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
