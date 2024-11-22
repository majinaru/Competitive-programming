#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

string bin (int x ){
    string ans;
    while(x){
        ans+= (x % 2) + '0';
        x/=2;
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;

    int num = 0;

    if(n == 2){
        int res;
        cout << "? 1 2" << endl;
        cin >> res;

        cout << "! " << (res ? "01" : "IMPOSSIBLE") << endl;
    }
    else{
        int l = 1;
        int r= 3;
        while(r <= n){
            int res;
            cout << "? "<< l << " "<< r << endl;
            cin >> res;

            if(res == 1){
                num |= (1 << n-l-1);
            }
            else if(res == 2){
                num |= (1 << n-r);
            }

            l++;
            r++;
        }
        cout << "! 0" + bin(num) << endl;
    }

    cout.flush();
}

int32_t main(){
    //cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
