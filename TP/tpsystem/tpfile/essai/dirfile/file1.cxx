// debut fichier file1.cxx, a mettre dans le repertoire dirfile
  #include <iostream>
  #include "notreEntete.h"

  int main() {
  int a,b;
  std::cin >> a >> b;
  int c (calculer(a,b));
  std::cout << c;
  return(0);
  }
// fin fichier file1.cxx
