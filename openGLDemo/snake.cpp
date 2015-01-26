#include<Windows.h>
#include<list>
#include<utility>
#include"SnakeGame.h"
using namespace std;



pair<int, int> Snake::get_ahead(int direction) {
	if (direction != -1) {
		this->direction = direction;
	}
	pair<int, int> head = loc.back();
	return pair<int, int>(head.first + diff_map[this->direction][0], head.second + diff_map[this->direction][1]);
}

Snake::Snake(){	
	memset(board,false,board_width*board_height);
	direction = get_random(1, 4);
	loc.push_front(pair<int, int>(get_random(0, board_width - 1), get_random(0, board_height - 1)));
	loc.push_front(get_ahead(-1));
}

bool Snake::go(int direction, pair<int, int>*gift) {
	pair<int, int>head = get_ahead(direction);
	if (gift&&head.first == gift->first&&head.second == gift->second)
	{
		delete gift;
		gift = NULL;
		pair<int, int> tail = loc.back();
		board[tail.first][tail.second] = false;
		loc.pop_back();
	}
	loc.push_front(head);

	if (head.first >= board_width || head.second >= board_height) return false;
	if (board[head.first][head.second])return false;
	board[head.first][head.second] = true;
	return true;
}

const list<pair<int, int>> Snake::get_loc() {
	return loc;
}

const bool** Snake::get_board() {
	return (bool**)board;
}
