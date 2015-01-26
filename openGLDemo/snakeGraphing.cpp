#include<list>
#include"opengldemo.h"
#include"SnakeGame.h"

static float grid_width = 1.0f;
static float grid_height = 1.0f;
static float grid_edge_width = 0.1f;
static float margin_left = -5.0f;
static float margin_top = -5.0f;
static float depth = -20.0f;

struct color {
	float red;
	float green;
	float blue;
};

int drawGrid(float left, float top, color c) {
	glLoadIdentity();
	glTranslatef(0, 0, depth);

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(left, top, 0.0f);
	glVertex3f(left, top - 2 * grid_edge_width - grid_height, 0.0f);
	glVertex3f(left + 2 * grid_edge_width + grid_width, top - 2 * grid_edge_width - grid_height, 0.0f);
	glVertex3f(left + 2 * grid_edge_width + grid_width, top, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(c.red, c.green, c.blue);
	glVertex3f(left + grid_edge_width, top - grid_edge_width, 0.0f);
	glVertex3f(left + grid_edge_width, top - grid_edge_width - grid_height, 0.0f);
	glVertex3f(left + grid_edge_width + grid_width, top - grid_edge_width - grid_height, 0.0f);
	glVertex3f(left + grid_edge_width + grid_width, top - grid_edge_width, 0.0f);
	glEnd();
	return true;
}
int drawMap() {
	static int bo = 0;
	color c;
	c.red = 0;
	c.green = 0;
	c.blue = 0;
	int i;
	int j;
	for (i = 0; i < board_height; i++) {
		for (j = 0; j <board_width; j++) {
			drawGrid(margin_left + j*(grid_width + grid_edge_width),
				margin_top + i*(grid_height + grid_edge_width),
				c);
		}
	}

	return true;
}
int drawSnake() {
	list<pair<int, int>> loc = snake.get_loc();
	color c;
	c.red = 1;
	c.green = 0;
	c.blue = 0;
	for (pair<int, int> pe : loc) {
		drawGrid(pe.first, pe.second, c);
	}
	return true;
}