#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, int> users;

  string a;
  int b;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    users.insert({a, b});
    sum += b;
  }

  int index = sum % n;

  int i = 0;
  for (auto u : users) {
    if (i == index) {
      cout << u.first << endl;
      return 0;
    }
    i++;
  }
}
