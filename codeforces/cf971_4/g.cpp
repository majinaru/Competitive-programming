#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n, k ,q;
    cin >> n >> k >> q;

    vector<int> vt(n);
    map<int,int> freq;
    set<pair<int, int>> rep;
    map<pair<int,int>, int> res;

    for(int i = 0; i < n; i++){
        cin >> vt[i];
    }

    for(int i = 0; i < k; i++){
        int val = vt[i] -i;
        if(rep.find({freq[val], val}) != rep.end())
            rep.erase({freq[val], val});
        freq[val]++;
        rep.insert({freq[val], val});
    }

    for(int i = k; i < n; i++){
        res[{i-k, i-1}] = k - rep.rbegin()->first;

        int val = vt[i] -i;
        if(rep.find({freq[val], val}) != rep.end())
            rep.erase({freq[val], val});
        freq[val]++;
        rep.insert({freq[val], val});

        int val_erase = vt[i-k] - (i - k);
        rep.erase({freq[val_erase], val_erase});
        freq[val_erase]--;
        rep.insert({freq[val_erase], val_erase});
    }
    res[{n-1-k +1, n-1}] = k - rep.rbegin()->first;

    for(int j = 0; j < q; j++){
        int l,r;
        cin >> l >> r;


        l--; r--;
        cout << res[{l, r}] << endl;
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
