#include <iostream>
#include "./supp/supp.h"

int main() {
  std::cout << "Choose rock (r), paper (p) or scissors (s)\n";
  char selected{getUserInput()};

  int converted{charToInt(selected)};

  std::cout << converted << '\n';

  return 0;
}
