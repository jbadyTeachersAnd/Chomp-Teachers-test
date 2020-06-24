#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include "Const.h"
#include "Console.h"

// TODO MS1: Add player structure

struct Player{
	int x;
	int y;
	int dx;
	int dy;
	char c;
	int color;
};

// TODO MS1: Add player function prototypes

struct Player initialize_Player(struct Player *p, int x, int y, int dx, int dy, char c, int color);
void draw_player(struct Player *p);
void player_AI(struct Player *p, int board[HEIGHT][WIDTH]);
void check_Player_Move(struct Player *p, int board[HEIGHT][WIDTH]);
void update_player(struct Player *p);

#endif // PLAYER_H
