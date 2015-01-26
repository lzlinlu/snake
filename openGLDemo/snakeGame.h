#include<list>
#include<utility>
#include<time.h>
#include<random>
using namespace std;
#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

extern const int diff_map[4][2];

static const int board_width = 10;
static const int board_height = 10;



class Snake {
public:
	Snake();
	bool go(int direction, pair<int, int>*gift);
	const list<pair<int, int>> get_loc();
	const bool** get_board();

private:
	int direction;
	bool board[board_height][board_width];
	list<pair<int, int>> loc;
	pair<int, int> get_ahead(int direction);
};


int get_random(int lower, int upper) {
	default_random_engine generator(time(NULL));
	uniform_int_distribution<int> distribution(lower, upper);
	return distribution(generator);
}

int drawMap();
int drawSnake();

extern Snake snake;

#endif