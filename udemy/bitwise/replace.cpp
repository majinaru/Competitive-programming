#include <bits/stdc++.h>
using namespace std;

// Recla Bit in N by M
// You are given two 32-bit numbers, n and M, and two bit positions i and j;
// Write a method to set all bits between i and j in N equal to M.
// M (becomes a substring of N locationed at and starting at j)
//
// example:
// n = 1000000000000;
// m = 10101;
// i = 2; j = 6
// output: 1001010100

void clearBitsInRange(int &n, int i, int j) {
  int a = (~0) << (j + 1);
  int b = (1 << i) - 1;
  int mask = a | b;
  n = n & mask;
}

void replaceBits(int &n, int i, int j, int m) {
  clearBitsInRange(n, i, j);
  int mask = m << i;
  n = n | mask;
}
int main() {

  int N = 15;
  int i = 1;
  int j = 3;
  int M = 2;

  replaceBits(N, i, j, M);
  cout << N << endl;
  return 0;
}
