#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
const int FPS = 100;
const int WIDTH = 9;
const int EZHEIGHT = 12;
const int MDHEIGHT = 18;
const int HDHEIGHT = 24;


void initField(char** field);

void difficulty();

void menu(bool gameGoing, int gamemode);

int keyboard();

int spawnCar(int& gamemode, int* carlanes, int** car);

void moveCar(int**& car, int*& carlanes);

void deleteCar(int**& car, int*& carlanes);

void render(char**& field, int*& player, int& gamemode, int* carlanes, int** car);

void updatePlayer(int*& player, int& dir);

bool winLoseCheck(int*& player, char**& field);

void resetPlayer(int*& player);

void resetCarPos(int*& carlanes, int**& car);

void leaderboard(int& currtime, int& fst, int& snd, int& trd);

void game(int*& player, int**& car, int*& carlanes, char**& field);