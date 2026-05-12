#include <iostream>

#include "random.h"

void clearScreen() {
	//Clear for Linux / Mac
#ifdef linux
	system("clear");
#endif

	//Clear for Windows
#ifdef _WIN32
	system("CLS");
#endif
}

int convertInput() {

	char userChar { };
	std::cin >> userChar;

	switch (userChar)
	{
		case 'r':
			return 0;
		case 'p':
			return 1;
		case 's':
			return 2;
		default:
			std::cout << "Not recognised, exiting." << '\n';
			return -1;
	}
}

int main() {

	clearScreen();
	std::cout << "Hewo" << '\n';
	std::cout << "Choose (r)ock, (p)aper, or (s)cissors:" << '\n';

	int checky {convertInput()};

	std::cout << Random::get(1,4) << '\n';
	std::cout << checky << '\n';

	return 0;
}
