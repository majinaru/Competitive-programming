#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int ll
using ll = long long;

void solve(){
    int n, m,v;
    cin >> n >> m >> v;

    vector<int> a(n);
    vector<int> prefx(n), sufx(n);
    vector<int> prefixo(n);
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // prefixo
    if(a[0] >= v){
        prefx[0] = 1;
    }
    else{
        sum+= a[0];
    }
    prefixo[0] = a[0];

    for(int i = 1; i < n; i++){
        sum+= a[i];
        if(sum >= v){
            prefx[i]++;
            sum = 0;
        }
        prefx[i] += prefx[i-1];

        prefixo[i] = a[i] + prefixo[i-1];
    }

    // sufixo
    sum = 0;
    if(a[n-1] >= v){
        sufx[n-1]= 1;
    }
    else{
        sum+= a[n-1];
    }
    for(int i = n-2; i >= 0; i--){
        sum+= a[i];
        if(sum >= v){
            sufx[i]++;
            sum = 0;
        }
        sufx[i] += sufx[i+1];
    }
  //  // print do prefx
  //  cout << "print do prefx " << endl;
  //  for(int i = 0; i < n; i++){
  //      cout << prefx[i] << " ";
  //  }
  //  cout << endl;
  //  

  //  // print do sufixo
  //  cout << " print do sufixo " << endl;
  //  for(int i = 0; i < n; i++){
  //      cout << sufx[i] << " ";
  //  }
  //  cout << endl;

  //  // print do prefixo
  //  cout << "print do prefixo " << endl;
  //  for(int i = 0; i < n; i++){
  //      cout << prefixo[i] << " ";
  //  }
  //  cout << endl;


    // buscar o melhor range
    int res = -1;
    for(int i = n-1; i >= 1 ; i--){
        if(sufx[i] >= m){
       //     cout << "prefixo[i-1] " << prefixo[i-1] << endl;
            res = max(res, prefixo[i-1]);
            break;
        }

        int pos = lower_bound(prefx.begin(), prefx.end(), m-sufx[i]) - prefx.begin();

        if(pos == n || sufx[i] + prefx[pos] <m){
            continue;
        }
       // cout << "i: " << i << endl;
       // cout << "sufx[i] " << sufx[i] << endl;
       // cout << "pos " << pos << endl;
       // cout << "prefx[pos] " << prefx[pos] << endl;
       // cout << "prefixo - prefixo " <<  prefixo[i-1] - prefixo[pos] << endl;

        res = max(res, prefixo[i-1] - prefixo[pos]);
    }
    for(int i = 0; i < n; i++){
        if(prefx[i] >= m){
         //  cout << "i " << i << endl;
         //  cout <<" prefixo[n-1] " << prefixo[n-1] << endl;
         //  cout << "prefixo[i] " << prefixo[i] << endl;
         //  cout <<" prefixo[n-1] - prefixo[i] " << prefixo[n-1] - prefixo[i] << endl;
           res = max(res, prefixo[n-1] - prefixo[i]);
            break;
        }
    }

    cout << res << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
