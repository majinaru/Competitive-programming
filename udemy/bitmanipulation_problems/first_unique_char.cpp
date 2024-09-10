#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
  unordered_map<char, int> cnt;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    cnt[s[i]]++;
  }

  for (int i = 0; i < n; i++) {
    if (cnt[s[i]] == 1)
      return i;
  }

  return -1;
}

int main() {
  string s;
  cin >> s;
  cout << firstUniqChar(s);
  cout << endl;
}
