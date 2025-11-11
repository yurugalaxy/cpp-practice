#include <iostream>

char getUserInput() {
  char x{};
  std::cin >> x;
  return x;
}

int charToInt(char x) {
  switch (x) {
  case 'r':
    return 0;
  case 'p':
    return 1;
  case 's':
    return 2;
  default:
    std::cout << "Unknown\n";
    return 5;
  }
}
