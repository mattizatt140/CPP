// Snake Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

bool gameOver;

const int width = 28;
const int height = 12;

int x, y, fruitX, fruitY, score;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

std::vector<int> tailX(100); std::vector<int> tailY(100);
int tailNum;

std::string userName;
std::string restart;
std::exception except;

void Setup();
void ShowConsoleCursor(bool showFlag);
void Draw();
void Input();
void Logic();
void WriteScoreBoard(std::string name);
void ReadScoreBoard();
void ClearScoreBoard();

int main()
{
	Setup();
	while (!gameOver) {
		ShowConsoleCursor(false);
		Draw();
		Input();
		Logic();
		Sleep(80);
		system("CLS");
	}
	std::cout << "GAME OVER" << std::endl;
	std::cout << "FINAL SCORE: " << score << std::endl;

	std::cout << std::endl << "ENTER NAME TO BE PLACED ON LEADERBOARD (PRESS 1 TO EXIT)" << std::endl;
	ShowConsoleCursor(true);
	getline(std::cin, userName);

	if (userName == "1") {
		return 0;
	}
	if (userName == "2") {
		ClearScoreBoard();
		return 0;
	}
	WriteScoreBoard(userName); std::cout << std::endl;
	system("CLS");
	std::cout << "********************" << std::endl << std::setw(15) << "LEADERBOARD" << std::endl << std::endl;
	ReadScoreBoard();
	std::cout << "********************" << std::endl;
	//system("PAUSE");
	return 0;
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Setup() {
	gameOver = false;
	srand(time(0));
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % (width - 1);
	fruitY = rand() % (height - 1) + 1;
	score;
}

void Draw() {
	for (int i = 0; i < width + 1; i++) {
		std::cout << "#";
	} std::cout << std::endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1) {
				std::cout << "#";
			}
			if (i == y && j == x) {
				std::cout << "O";
			}
			else if (i == fruitY && j == fruitX) {
				std::cout << "$";
			}
			else {
				bool print = false;
				for (int k = 0; k < tailNum; k++) {
					if (tailX.at(k) == j && tailY.at(k) == i) {
						std::cout << "o";
						print = true;
					}
				}
				if (!print) {
					std::cout << " ";
				}
			}
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < width + 1; i++) {
		std::cout << "#";
	} std::cout << std::endl;

	std::cout << "SCORE: " << score << std::endl;
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'f':
			std::cout << "PAUSED" << std::endl;
			system("PAUSE");
		}
	}
}

void Logic() {
	int prevX = tailX.at(0);
	int prevY = tailY.at(0);
	int prev2X, prev2Y;
	tailX.at(0) = x;
	tailY.at(0) = y;
	for (int i = 1; i < tailNum; i++) {
		prev2X = tailX.at(i);
		prev2Y = tailY.at(i);
		tailX.at(i) = prevX;
		tailY.at(i) = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x == width - 1 || y == height || x < 0 || y < 0) {
		gameOver = true;
	}
	for (int i = 0; i < tailNum; i++) {
		if (tailX.at(i) == x && tailY.at(i) == y) {
			gameOver = true;
		}
	}
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % (width - 1);
		fruitY = rand() % (height - 1);
		std::ofstream recordFile("fruitXY.txt", std::ios_base::app);
		recordFile << "[" << fruitX << ", " << fruitY << "]" << std::endl;
		recordFile.close();
		tailNum++;
	}
}

void WriteScoreBoard(std::string name) {
	std::ofstream writeScore("scoreBoard.txt", std::ios_base::app);
	if (writeScore.is_open()) {
		writeScore << name << " " << score << std::endl;
	}
	else {
		throw except;
	}
	writeScore.close();
}

void ReadScoreBoard() {
	std::ifstream readScore("scoreBoard.txt");
	if (readScore.is_open()) {
		std::string line;
		while (getline(readScore, line)) {
			std::cout << line << std::endl;
		}
	}
	else {
		throw except;
	}
	readScore.close();
}

void ClearScoreBoard() {
	std::ofstream clearFile("scoreBoard.txt", std::ios_base::trunc);
}