// #include "random.h"
#include <array>
// #include <cstdint>
// #include <fstream>
#include <iostream>
// #include <string>

// #include "base.h"

void clearScreen() {
    // Clear for Linux / Mac
#ifdef linux
    system("clear");
#endif

    // Clear for Windows
#ifdef _WIN32
    system("CLS");
#endif
}

// void writeFile() {
//     Tile tileing;
//     for (int i{0}; i < 64; ++i)
//         tileing = {i, i, Random::get(1, 5)};
//
//     std::ofstream file("player.dat", std::ios::binary);
//     file.write((char *)&tileing, sizeof(tileing));
//     file.close();
// };
//
// void readFile() {
// 	std::vector<Piece> tileing;
//     std::ifstream file("pieces.dat", std::ios::binary);
//     file.read((char *)&tileing, sizeof(tileing));
//     file.close();
//     std::cout << tileing[0].x << ", " << tileing[0].y << ", " <<
//     tileing[0].piece
//               << '\n';
// };
//
// void writeFile(std::vector<Piece> currBoard) {
//     std::ofstream file("pieces.dat", std::ios::binary);
//     file.write((char *)&currBoard, sizeof(currBoard));
//     file.close();
// };

// It would be really sick to put all this info into a bitset
// but I'm not good enough to figure that out rn
// #makeitexistfirst

enum Stats {
    alive,
    taken,
    white,
    black,
};

struct Piece {
    char  name{' '};
    int   score;
    int   rank;
    int   file;
    Stats onBoard;
    Stats team;
};

void drawScreen(const std::array<Piece, 16>         &sidePiece,
                std::array<std::array<Piece, 8>, 8> &boardState) {
    std::string_view wTeam{"\033[1;36m"};
    std::string_view bTeam{"\033[1;37m"};
    std::string_view bSquare{"\033[1;41m"};
    clearScreen();

    boardState = {{}};

    for (auto &awa : sidePiece) {
        boardState[awa.file][awa.rank] = awa;
    };

    std::cout << '\n';

    for (auto &arow : boardState) {
        for (auto &thing : arow) {
            std::cout << thing.name << ' ';
        };
        std::cout << '\n';
    };
};

void processInput(Piece &sele) {
    char newRank{};
    char newFile{};
    std::cin >> newRank >> newFile;
	sele.rank = newRank - 'a';
	sele.file = newFile - '0';
};

int main() {

    Piece rookW1{'R', 1, 0, 0, Stats::alive, Stats::white};
    Piece knightW1{'N', 1, 1, 0, Stats::alive, Stats::white};
    Piece bishopW1{'B', 1, 2, 0, Stats::alive, Stats::white};
    Piece queenW{'Q', 1, 3, 0, Stats::alive, Stats::white};
    Piece kingW{'K', 1, 4, 0, Stats::alive, Stats::white};
    Piece bishopW2{'B', 1, 5, 0, Stats::alive, Stats::white};
    Piece knightW2{'N', 1, 6, 0, Stats::alive, Stats::white};
    Piece rookW2{'R', 1, 7, 0, Stats::alive, Stats::white};
    Piece pawnW1{'P', 1, 0, 1, Stats::alive, Stats::white};
    Piece pawnW2{'P', 1, 1, 1, Stats::alive, Stats::white};
    Piece pawnW3{'P', 1, 2, 1, Stats::alive, Stats::white};
    Piece pawnW4{'P', 1, 3, 1, Stats::alive, Stats::white};
    Piece pawnW5{'P', 1, 4, 1, Stats::alive, Stats::white};
    Piece pawnW6{'P', 1, 5, 1, Stats::alive, Stats::white};
    Piece pawnW7{'P', 1, 6, 1, Stats::alive, Stats::white};
    Piece pawnW8{'P', 1, 7, 1, Stats::alive, Stats::white};

    std::array<Piece, 16> whiteSide{
        rookW1, knightW1, bishopW1, queenW, kingW,  bishopW2, knightW2, rookW2,
        pawnW1, pawnW2,   pawnW3,   pawnW4, pawnW5, pawnW6,   pawnW7,   pawnW8};

    std::array<std::array<Piece, 8>, 8> awawa{{}};

    bool active{true};

    while (active) {

		drawScreen(whiteSide, awawa);
        processInput(whiteSide[1]);
    };

    return 0;
}
