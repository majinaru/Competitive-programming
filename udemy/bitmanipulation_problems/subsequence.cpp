#include <bits/stdc++.h>
using namespace std;

void overLayNumber(char arr[], int number) {

  int j = 0;
  while (number > 0) {
    int last_bit = number & 1;
    if (last_bit) {
      cout << arr[j];
    }

    j++;
    number = number >> 1;
  }
  cout << endl;
}

void generateAllSubsequences(char arr[]) {
  int n = strlen(arr);

  for (int i = 0; i < (1 << n);
       i++) { // 1<<n = 2^n é o numero de possibilidades de conjunto das partes
    overLayNumber(arr, i);
  }
  return;
}

int main() {

  char arr[10000];
  cin >> arr;

  generateAllSubsequences(arr);
}
