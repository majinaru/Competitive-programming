#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;


void solve(){
    int n, m;
    cin >> n >>  m;

    vector<pair<int, int>> pessoa(n+1);
    vector<tuple<int, int, int>> ps;

    for(int i = 0; i < n + 1; i++){
        pessoa[i] = {0, i};
    }

    for(int i = 0; i < m; i++){
        int a, b,c;
        cin >> a >> b >> c;

        pessoa[a].first-=c;
        pessoa[b].first+=c;
    }

    sort(pessoa.begin()+1, pessoa.end(), greater<pair<int, int>>());

    int cont = 0;
    int L = 1, R = n;

    while(L< R){
        int aux = pessoa[R].first;
        pessoa[R].first = min(pessoa[R].first + pessoa[L].first, 0);
        if(pessoa[L].first > 0){
                        ps.push_back(make_tuple(R, L, pessoa[L].first - (pessoa[L].first + aux))); 
                    cont++;
        }
        pessoa[L].first = max(pessoa[L].first + aux, 0);

        if(pessoa[R].first == 0){
            R--;
        }
        if(pessoa[L].first == 0){
            L++;
        }
    }

    cout << cont << endl;

    for(int i = 0; i < cont; i++){
        cout << get<0>(ps[i]) << " " << get<1>(ps[i]) << ' ' << get<2>(ps[i]) << '\n';
    }

}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();

}
