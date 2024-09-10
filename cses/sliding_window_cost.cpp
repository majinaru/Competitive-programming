#include <bits/stdc++.h>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define endl '\n'
using ll = long long;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename U>
using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> vt(n);
    ordered_set<pair<int,int>> st;

    for(int i = 0; i < n; i++){
        cin >> vt[i];
        
        if(k > i)
            st.insert({vt[i], i});
    }

    int ksum = 0;
    for(int i = 0; i < k ; i++){
        ksum+= abs(vt[i] - st.find_by_order((k+2-1)/2 -1)->first);
    }
    
    for(int i = k; i < n; i++){
        cout <<  ksum << " ";

        int old = abs(vt[i-k] - st.find_by_order((k+2-1)/2 -1)->first);
        st.erase({vt[i-k], i-k});

        cout << " mediana: " << st.find_by_order((k+2-1)/2 -1)->first << "old : " << old <<  endl;
        
        ksum= abs(ksum - old); 

        st.insert({vt[i], i});

        int novo = abs(vt[i] - st.find_by_order((k+2-1)/2-1)->first);
        ksum+= novo; 
    }
    cout << ksum << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
