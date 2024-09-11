#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

set<pair<int,int>> t1, t2;
int s1, s2;
int k;

void balanceia(){ 
    if(t1.size() == 0 && t2.size() == 0)
        return;

    pair<int, int> aux;
    int corte = (k+1)/2;

    if(t1.size() > corte){ 
        aux = *t1.rbegin();
        t1.erase(aux);
        t2.insert(aux);

        s1-= aux.first;
        s2+= aux.first;
    }
    else if(t1.size() < corte){
        aux = *t2.begin();
        t2.erase(aux);
        t1.insert(aux);

        s2-= aux.first;
        s1+= aux.first;
    }

    if(t2.size() && t1.rbegin()->first > t2.begin()->first){
        aux = *t1.rbegin();
        pair<int,int> aux2 = *t2.begin();

        t2.insert(aux);
        t1.erase(aux);
        s1-= aux.first;
        s2+= aux.first;

        t1.insert(aux2);
        s1+= aux2.first;
        s2-= aux2.first;
        t2.erase(aux2);
    }
}

void dec(pair<int,int> delet){
    pair<int,int> m = *t1.rbegin();

    if(m.first < delet.first){
        s2-= delet.first;
        t2.erase(delet);
    }
    else{
        s1-= delet.first;
        t1.erase(delet);
    }


    balanceia();
}

void add(pair<int,int> ins){
    t2.insert(ins);
    s2+= ins.first;
    balanceia();
}


void solve() {
    int n ;
    cin >> n >> k;

    vector<int> vt(n);
    set<pair<int,int>> st;
    s1 = 0;
    s2= 0;

    for(int i = 0; i < n; i++){
        cin >> vt[i];

        if(k> i)
            st.insert({vt[i], i});
    }

    // inserção ate k
    int cont = 0;
    for(auto v: st){
        if(cont <= (k+1)/2-1){
            t1.insert(v);
            s1+= v.first;
        }
        else{
            t2.insert(v);
            s2+= v.first;
        }
        cont++;
    }

    // janela deslizante
    for(int i = k; i < n; i++){
        int sz1 = t1.size();
        int sz2 = t2.size();
        int m = t1.rbegin()->first;


        if(sz1 == 1){
            cout << s2-sz2*m << " ";
        }
        else
            cout << sz1*m - s1 + s2 - sz2*m << " ";

        dec({vt[i-k], i-k}); 
        add({vt[i], i});


    }
    int sz1 = t1.size();
    int sz2 = t2.size();
    int m = t1.rbegin()->first;

    if(sz1 == 1){
        cout << s2-sz2*m << endl;
    }
    else
        cout << sz1*m - s1 + s2 - sz2*m << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
