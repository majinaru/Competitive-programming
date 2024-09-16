#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int ll
using ll = long long;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    set<int> t;
    for(int i = 0; i < m;  i++){
        int a;
        cin >> a;
        t.insert(a);

    }



    for(int i = 0; i < q; i++){
        int d;
        cin >> d;

        auto it = t.lower_bound(d);

        auto prev_it = prev(it);
        if(it == t.begin()){
            prev_it = t.begin();
        }

        if(it == t.end()){
            cout << n - *t.rbegin()<< endl;
        }
        if(*it  > d && it == t.begin()){
            cout << *it - 1 << endl;
        }
        else if(*it > d && it!= t.begin()){
            cout << (*it- *prev_it)/2<< endl;
        }
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
