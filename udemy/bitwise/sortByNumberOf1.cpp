#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
  int setA = __builtin_popcount(a);
  int setB = __builtin_popcount(b);

  if (setA == setB) {
    return a < b;
  }

  return setA < setB;
}

vector<int> sortByBits(vector<int> arr) {
  sort(arr.begin(), arr.end(), cmp);

  return arr;
}
