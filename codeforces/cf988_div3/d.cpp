#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

void solve(){
    int n, m, l;
    cin >> n >> m >> l;

    map<int, int> path;

    for(int i = 0; i < n; i++){
        int L, R;
        cin >> L >> R;

        path[L]+= R-L + 1;
    }
    


    int ans = 0;

    map<int, vector<int>> vt;
    priority_queue<int> bag;
    int energia = 0;

    auto verifica_bag = [&](int valor) -> void
    {
        while(!bag.empty() && energia < valor){
            energia += bag.top();
//            cout << "bag.top() " << bag.top() << endl;
            ans++;
            bag.pop();
        }
    };

    for(int i = 0; i < m; i++){
        int x, v;
        cin >> x >> v;

        vt[x].push_back(v);
    }


 //  // print prefx 
 //   for(int i = 0; i <= l; i++){
 //       cout << path[i] << " ";
 //   }
 //   cout << endl;


    int i = 0;
    for(auto v : path){
        if(v.second > energia){
            verifica_bag(v.second);

            if(v.second > energia){
                cout << -1 << endl;
                return;
            }
        }

        // encontrar menores que v.first
        // pesado dms
        for(auto u : vt){
            if(v.first > u.first){
                for(auto x : u.second){
                    bag.push(x);
                }
            }
        }

    }

    cout << ans << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
