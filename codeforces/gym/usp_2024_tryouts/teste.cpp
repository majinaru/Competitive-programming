
edit_distance(i, j) {
  if (i == n || j == n)
    return n - min(i, j); // adiciona
  if (s[i] == s[j])       // iguais
    edit_distance(i + 1, j + 1);
  else {
    s[i] = s[j]; // replace
    edit_distance(i + 1, j + 1);
  }
}
