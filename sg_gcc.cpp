#include <conio.h>
#include <iostream>
#include <ctime>

//using std namespace
using namespace std;

//GlobalVariables
bool gameOver{ true };

/*	create a var that hold			position of snake,
*									direction of input value
*									position of fruit
*									width and height of the board game
**
*/
const int w_board{ 20 };
const int h_board{ 20 };

struct Position {
	int x {};
	int y {};
};

Position snake_p;				//create snake position
Position fruit_p;				//create fruit position

//Enum variable for the direction of the snake game
enum Direction {
	NONE,
	LEFT,
	RIGHT,
	UP,
	DOWN,
};
Direction dir{Direction::NONE};

//Score of the game
int score{ 0 };

//Snake Tails
Position snake_t[10]; // want more? add more zero@@
int tailsIndex{ 0 };

/*
----------------------------------------------------------------------------
*/

//	Function for the game;
void gameSetup();
void draw();
void input();
void logic();

//create a fucntion that function the snake tail
void snakeTail();

//initial gameplay
int main() {
	srand(time(NULL));
	gameSetup();						//set gameOver variable is false. and play the game

	while (!gameOver) {
		draw();
		input();
		logic();
	}

	//Sleep(1);							//For WIndows
	//sleep(1);							//For Linux

	std::cout << gameOver;				//this statement for the game test while coding
	
	return 0;
}

//--------------------------------------------------------------------------

void gameSetup() {

	//when game over equal "true". it end the game. 
	//false the game is running##
	gameOver = false;

	//Position initial setup
	snake_p.x = w_board / 2;
	snake_p.y = h_board / 2;
	fruit_p.x = rand() % w_board;
	fruit_p.y = rand() % h_board;
}

void draw() {

	system("cls");					//for window
	//system("clear");				//for linux
	std::cout << "Hello Game\n";
	
	for (int i = 1; i <= h_board; ++i) {
		for (int j = 1; j <= w_board; ++j) {
			if (i == 1 || i == h_board || j == 1 || j == w_board) {
				std::cout << "#";
			}
			else if ((i == snake_p.y && j == snake_p.x)) {
				std::cout << "*";
			}
			else if (snake_t->x == i && snake_t->y == j) {
				std::cout << "*";
			}
			else if (i == fruit_p.y && j == fruit_p.x) {
				std::cout << "!";
			}
			else {
				std::cout << " ";
			}



		}

		std::cout << '\n';
	}

	//system("cls");
}

void input() {

	if (_kbhit()) {
		switch (_getch()) {
		case 'j':
			dir = DOWN;
			break;
		case 'k':
			dir = UP;
			break;
		case 'h':
			dir = LEFT;
			break;
		case 'l':
			dir = RIGHT;
			break;
		case 'x':
			gameOver = true;
			
		}

	}

}

void logic() {
	switch (dir) {
	case UP:
		snake_p.y--;
		break;
	case DOWN:
		snake_p.y++;
		break;
	case RIGHT:
		snake_p.x++;
		break;
	case LEFT:
		snake_p.x--;
		break;
	}

	//check if game over
	if (snake_p.x > w_board ||
		snake_p.x < 0 ||
		snake_p.y < 0 ||
		snake_p.y > h_board)
	{
		gameOver = true;
	}

	//check the score of the game
	if (fruit_p.x == snake_p.x && fruit_p.y == snake_p.y) {
		++score;

		++tailsIndex; 
		//snakeTail();					//test

		fruit_p.x = rand() % w_board;
		fruit_p.y = rand() % h_board;
	}

	//snakeTail();						//TEST
}

void snakeTail() {
	//struct array for snake tail varialbes
	//var: snake_t << array
	if (tailsIndex == 1) {
		snake_t->y = snake_p.y;
		snake_t->x = snake_p.x;
	}
}
