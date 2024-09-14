#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
        if(it ==  t.end()){
            it = prev(it);
        }
        auto next_it = next(it);
        auto prev_it = prev(it);


        int ans = -1;
        if(*it > d){
            if(prev_it != it)
                ans = (*it - *prev_it)/2;
            else
                ans = *(prev_it)-1;
        }
        else{
            if(d- *it <= 1 || (next_it != t.end() && *next_it - d <=1)
                    || (prev_it != it && abs(d - *prev_it) <=1)){
                ans = 0;
            }
            else if(next_it != t.end()){
                ans = (*(next_it) - *it)/2;
            }
            else
                ans = (n - *it);
        }

        cout << ans << endl;

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
