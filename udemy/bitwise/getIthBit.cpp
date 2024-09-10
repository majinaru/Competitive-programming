#include <bits/stdc++.h>
using namespace std;
int getIthBit(int &n, int i) {
  int mask = (1 << i);           // move o 1 i vezes a esquerda
  return (n & mask) > 0 ? 1 : 0; // retorna o iésimo bit de n
}

int setIthBit(int n, int i) { return n | (1 << i); }
void clearIthBit(int &n, int i) {
  int mask = ~(1 << i);
  n = n & mask;
}

void updateIthBit(int n, int i, int v) { // v = 1 ou 0
  clearIthBit(n, i);
  int mask = (v << i);

  n = n | mask; // torna o valor n com ith bit mudado para v
}

void clearLastBits(int &n, int i) {
  int mask = (-1 << i);
  n = n & mask;
}

void clearBitsInRange(int &n, int i, int j) {
  int a = (~0) << (j + 1);
  int b = (1 << i) - 1;
  int mask = a | b;

  n = n & mask;
}

int main() {
  int n = 31;
  int i = 1;
  int j = 3;

  // cout << getIthBit(n, i) << endl;

  // clearIthBit(n, i);
  // cout << n << endl;

  clearBitsInRange(n, i, j);
  cout << n << endl;
}
