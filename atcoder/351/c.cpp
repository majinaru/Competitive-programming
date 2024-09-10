#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;

    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a.push_back(ai);

        while (a.size() > 1 && a.back() == a[a.size() - 2]) {
            int merged_value = a.back() + 1;  
            a.pop_back();  
            a.pop_back();  
            a.push_back(merged_value); 
        }
    }

    cout << a.size() << endl;
    return 0;
}
