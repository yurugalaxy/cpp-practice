#include <iostream>

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


int main() {

	clearScreen();
	std::cout << "Hewo" << '\n';

	return 0;
}
