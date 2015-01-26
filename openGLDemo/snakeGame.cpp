#include<Windows.h>
#include<time.h>
#include"SnakeGame.h"

const int keymap[4] = { VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT };
const int diff_map[4][2] = { { 0, 1 },{ 0, -1 },{ -1, 0 },{ 1, 0 } };

static int direction_command = -1;
static const int INTERVAL = 1000;
static int last_moving_time = 0;

pair<int, int>* gift = NULL;

Snake snake;

int play(bool keys[]);

pair<int, int>* gift_generator(const bool(&board)[board_width][board_height]);

int game(bool keys[]) {
	int re = play(keys);
	drawMap();
	drawSnake();
	return re;
}


int play(bool keys[]) {
	static int direction = -1;
	int current_time = time(NULL);
	if (current_time - last_moving_time<INTERVAL) {
		if (keys[VK_UP]) {
			keys[VK_UP] = false;
			direction = 0;
		}
		else if (keys[VK_DOWN]) {
			keys[VK_DOWN] = false;
			direction = 1;
		}
		else if (keys[VK_LEFT]) {
			keys[VK_LEFT] = false;
			direction = 2;
		}
		else if (keys[VK_RIGHT]) {
			keys[VK_RIGHT] = false;
			direction = 3;
		}
		return true;
	}
	return snake.go(direction, gift_generator(snake.get_board()));
}

pair<int, int>* gift_generator(const bool **board ) {
	if (gift) {
		return gift;
	}
	int x;
	int y;
	for (;;) {
		x = get_random(0, board_width);
		y = get_random(0, board_height);
		if (!board[x][y])
		{
			gift = new pair<int, int>(x, y);
			break;
		}
	}
	return gift;

}







