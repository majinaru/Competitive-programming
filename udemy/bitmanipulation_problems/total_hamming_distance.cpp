#include <bits/stdc++.h>
using namespace std;

int numberDiff(int i) {
  int cont = 0;
  while (i > 0) {
    i = i & (i - 1);
    cont++;
  }
  return cont;
}

int hammingdistance(int x, int y) { return numberDiff(x ^ y); }

int totalHammingDistance(vector<int> nums) {
  int n = nums.size();
  int total = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      total += hammingdistance(nums[i], nums[j]);
    }
  }

  return total;
}

int main() {}
