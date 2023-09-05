#include "Header.h"

int main()
{
    bool gameGoing = 0;
    int gamemode = 1;
    int fst = 0, snd = 0, trd = 0;
    srand(time(NULL));
    menu(gameGoing, gamemode);
    system("cls");
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    int* carlanes=new int[24];
    int** car = new int* [24] {};
    for (int i = 0; i < 24; i++) {
        car[i] = new int[WIDTH] {};
    }

    char** field = new char* [24];
    for (int i = 0; i < 24; i++) {
        field[i] = new char[WIDTH] {};
    }

    int* player = new int[3] { (WIDTH / 2), (height - 1), 0 };
    initField(field);
    game(player, car, carlanes, field);
}
