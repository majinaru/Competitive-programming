#include <bits/stdc++.h>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename U>
using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


//  NOT FINISHED AND IMPOSSIBLE ALSO

int s1, s2;
int n, k;
ordered_set<pair<int,int>> st;
pair<int, int> eliminado;

void dec(int element, int pos){
        pair<int,int> aux = {element, pos};
        pair<int, int> last =  *st.find_by_order((st.size()+1)/2-1);

        if(aux < *st.find_by_order((st.size()+1)/2-1))
            s1-= element;
        else
            s2-= element;

        eliminado = aux;
        st.erase({element, pos});

        pair<int,int> novo = *st.find_by_order((st.size()+1)/2-1);

        if( last < novo ){
            s2-= novo.first;
        }
}

void inc(int element, int pos, pair<int,int> last){

    pair<int,int> aux = {element, pos};
    st.insert({element, pos});
    pair<int,int> novo = *(st.find_by_order((st.size()+1)/2-1));

    if(aux < novo){
        s1+= element;
    }
    else if(aux > novo){
        s2+= element;
    }

    if(novo > last && aux != novo){
        s2-= novo.first;
        s1+= last.first;
    }
    else if(novo < last && last != eliminado){
        s2+= last.first;
        s1-= last.first;
    }

}

void solve() {
    cin >> n >> k;
    vector<int> vt(n);

    for(int i = 0; i < n; i++){
        cin >> vt[i];

        if(k>i)
            st.insert({vt[i], i});
    }

    s1 = 0;
    s2 = 0;

    int cont = 0;
    for(auto v: st){
        if(cont < (k-1)/2){
            s1+= v.first;
        }
        else if(cont > (k-1)/2){
            s2+= v.first;
        }
        cont++;
    }

    for(int i = k; i < n ;i++){
        cout << s2 - s1 << " ";

        pair<int,int> last = *st.find_by_order((st.size()+1)/2-1);
        dec(vt[i-k], i-k);

        /*cout << "APOS DECREMENTO " <<endl;*/
        /*for(auto v: st){*/
        /*    cout << v.first << " " ;*/
        /*}*/
        /*cout << endl;*/
        /**/
        /*cout << s1 << " " << s2 << endl;*/
        /*return;*/

        inc(vt[i], i, last);
        }
        cout << s2 - s1<< endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
