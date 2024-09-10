#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i= 0; i < n; i++){
        cin >> nums[i];
    }

    string s;
    cin >> s;

    vector<ll> prefx(n);

    prefx[0] = nums[0];
    for(int i = 1; i < n; i++){
        prefx[i] = prefx[i-1] + nums[i];
    }

    int L = 0, R = n-1;
    ll sum = 0;

    while(L<R){
        if(s[L] == 'R'){
            L++;
            continue;
        }

        if(s[L]== 'L' && s[R] == 'R'){
            if(L == 0){
             sum+= prefx[R];
            }
            else
             sum+= prefx[R] - prefx[L-1];
             L++;
             R--;
             continue;
         }
        else if(s[L] == 'L'){
            R--;
        }
        else{
            L++;
        }
    }

    cout << sum << endl;
    
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--){
      solve();
  }
}
