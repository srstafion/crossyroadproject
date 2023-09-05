#include "Header.h"
bool gameGoing = 0;
int gamemode = 1;
int fst = 0, snd = 0, trd = 0;
void difficulty() {
    cout << "  > New Game" << endl;
    int b;
    cout << "==========================================" << endl;
    cout << "|     Select difficulty from 1 to 3      |" << endl;
    cout << "|    (1 - Easy, 2 - Medium, 3 - Hard)    |" << endl;
    cout << "==========================================" << endl;
    cin >> b;
    if (b == 1) {
        gamemode = 1;
        gameGoing = 1;
    }
    else if (b == 2) {
        gamemode = 2;
        gameGoing = 1;
    }
    else if (b == 3) {
        gamemode = 3;
        gameGoing = 1;
    }
}

void menu(bool gameGoing, int gamemode) {
    int a;
    system("cls");
    cout << "==========================================" << endl;
    cout << "|   _                    __              |" << endl;
    cout << "|  / ` _ _   _  _        )_) _   _   _ ) |" << endl;
    cout << "| (_. ) (_) (  ( (_(    / ( (_) (_( (_(  |" << endl;
    cout << "|           _) _)  _)                    |" << endl;
    cout << "|                                        |" << endl;
    cout << "|           Select your action           |" << endl;
    cout << "|            1. New Game                 |" << endl;
    cout << "|            2. Highscore                |" << endl;
    cout << "==========================================" << endl;
    cin >> a;
    if (a == 1) {
        difficulty();
        system("cls");
    }
    else if (a == 2) {
        system("cls");
        cout << "==========================================" << endl;
        cout << "|               Leaderboards             |" << endl;
        cout << "|                1. " << fst << "                    |" << endl;
        cout << "|                2. " << snd << "                    |" << endl;
        cout << "|                3. " << trd << "                    |" << endl;
        cout << "==========================================" << endl;
        cin >> a;
        if (a == 0) menu(gameGoing, gamemode);
    }
}

int keyboard() {
    if (_kbhit()) 
    {
        switch (_getch()) {
        case 80:
            return 1;
            break;
        case 72:
            return 2;
            break;
        case 75:
            return 3;
            break;
        case 77:
            return 4;
            break;
        }
    }
}

int spawnCar(int& gamemode, int* carlanes, int** car) {
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    for (int i = 0; i < height; i++) {
        if (carlanes[i] == 1) {
            if (rand() % 6 == 1) {
                car[i][0] = 1;
                return car[i][0];
            }
        }
    }
}

void moveCar(int**& car, int*& carlanes) {
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    for (int i = 0; i < height; i++) {
        if (carlanes[i] == 1) {
            for (int j = WIDTH - 1; j > 0; j--) {
                swap(car[i][j], car[i][j - 1]);
            }
        }
    }
}

void deleteCar(int**& car, int*& carlanes) {
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    for (int i = 0; i < height; i++) {
        if (carlanes[i] == 1) {
            if (car[i][8] == 1) car[i][8] = 0;
        }
    }
}

void render(char**& field, int*& player, int& gamemode, int* carlanes, int** car)
{
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (carlanes[i] == 1) field[i][j] = '#';
            else field[i][j] = '.';
            field[0][j] = '=';
        }
    }
    field[player[1]][player[0]] = '@';
    for (int i = 0; i < height; i++) {
        if (car[i][0] == 1) field[i][0] = 'n';
    }
    for (int i = 0; i < height; i++) {
        if (carlanes[i] == 1)
        {
            for (int j = 0; j < WIDTH; j++) {
                if (car[i][j] == 1)field[i][j] = 'n';
            }
        }
    }
    system("cls");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

void updatePlayer(int*& player, int& dir) {
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    player[2] = dir;
    switch (player[2]) {
    case 4:
        if (player[0] < WIDTH - 1) {
            player[0]++;
        }
        break;
    case 3:
        if (player[0] > 0) {
            player[0]--;
        }
        break;
    case 2:
        if (player[1] > 0) {
            player[1]--;
        }
        break;
    case 1:
        if (player[1] < height - 1) {
            player[1]++;
        }
        break;
    }
}

void initField(char** field) {
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < WIDTH; j++)
            field[i][j] = '.';
    }
}

bool winLoseCheck(int*& player, char**& field) {
    if (player[1] == 0) {
        return 0;
    }
    else if (field[player[1]][player[0]] == 'n') {
        return 0;
    }
    else return 1;
}

void resetPlayer(int*& player) {
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    player[0] = (WIDTH / 2);
    player[1] = (height - 1);
}

void resetCarPos(int*& carlanes, int**& car) {
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    for (int i = 1; i < height - 2; i++) {
        carlanes[i] = 0;
    }
    for (int i = 1; i < height - 2; i++) {
        for (int j = 0; j < WIDTH; j++) {
            car[i][j] = 0;
        }
    }
    for (int i = 1; i < height - 2; i++) {
        carlanes[i] = rand() % 2;
    }
}
void leaderboard(int& currtime, int& fst, int& snd, int& trd) {
    currtime = currtime / 60;
    if (fst == 0) fst = currtime;
    if (currtime < fst) {
        trd = snd;
        snd = fst;
        fst = currtime;
    }
    else if (currtime < snd && currtime > fst && currtime < trd) {
        trd = snd;
        snd = currtime;
    }
    else if (currtime < trd && currtime > snd && currtime >> fst) {
        trd = currtime;
    }
}

void game(int*& player, int**& car, int*& carlanes, char**& field) {
    int currtime = 0;
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    initField(field);
    resetCarPos(carlanes, car);
    resetPlayer(player);
    while (gameGoing == 1) {
        int dir = keyboard();
        updatePlayer(player, dir);
        deleteCar(car, carlanes);
        moveCar(car, carlanes);
        spawnCar(gamemode, carlanes, car);
        render(field, player, gamemode, carlanes, car);
        currtime += 8;
        gameGoing = winLoseCheck(player, field);
        Sleep(FPS);
        keyboard();
    }
    if (player[1] == 0) {
        system("cls");
        if (gamemode == 3) leaderboard(currtime, fst, snd, trd);
        currtime = 0;
        int a;
        cout << "===================================" << endl;
        cout << "| \\_)_        \\  ^   / o  __ |    |" << endl;
        cout << "|  / (_) (_(    \\/ \\/ /  / / o    |" << endl;
        cout << "|  Would you like to play again?  |" << endl;
        cout << "|   (1 - Play Again, 2 - Menu)    |" << endl;
        cout << "===================================" << endl;
        cin >> a;
        if (a == 1) {
            system("cls");
            difficulty();
            resetPlayer(player);
            resetCarPos(carlanes, car);
            game(player, car, carlanes, field);
        }
        else if (a == 2) {
            system("cls");
            menu(gameGoing, gamemode);
            resetPlayer(player);
            resetCarPos(carlanes, car);
            game(player, car, carlanes, field);
        }
    }
    else {
        system("cls");
        int a;
        cout << "=====================================" << endl;
        cout << "|  \\_) _         )   _   _   _  |   |" << endl;
        cout << "|  /  (_)(_(    (__ (_) (   )_) o   |" << endl;
        cout << "|                       _) (_       |" << endl;
        cout << "|   Would you like to play again?   |" << endl;
        cout << "|    (1 - Play Again, 2 - Menu)     |" << endl;
        cout << "=====================================" << endl;
        cin >> a;
        if (a == 1) {
            system("cls");
            difficulty();
            resetPlayer(player);
            resetCarPos(carlanes, car);
            game(player, car, carlanes, field);
        }
        else if (a == 2) {
            system("cls");
            menu(gameGoing, gamemode);
            resetPlayer(player);
            resetCarPos(carlanes, car);
            game(player, car, carlanes, field);
        }
    }
}