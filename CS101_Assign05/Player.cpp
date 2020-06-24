#include "Player.h"

// TODO MS1: Add player functions
struct Player initialize_Player(struct Player *p, int x, int y, int dx, int dy, char c, int color){
	
	p->x = x;
	p->y = y;
	p->dx = dx;
	p->dy = dy;
	p->c = c;
	p->color = color;
	
	return *p;
}

void draw_player(struct Player *p){
	
	cons_move_cursor(p->y,p->x);
	cons_change_color(p->color, BLACK);
	cons_printw("%c", p->c);
}

void player_AI(struct Player *p, int board[HEIGHT][WIDTH]){
	int key = cons_get_keypress();
	
	if(key==LEFT_ARROW){
		p->dx = -1;
		p->dy = 0;
		
	}
	else if(key==RIGHT_ARROW){
		p->dx = 1;
		p->dy = 0;
		
	}
	else if(key==UP_ARROW){
		p->dy = -1;
		p->dx = 0;
		
	}
	else if(key==DOWN_ARROW){
		p->dy = 1;
		p->dx = 0;
		
	}
	else{
		p->dx = p->dx;
		p->dy = p->dy;
	
	}
	
	check_Player_Move(p, board);
}

void check_Player_Move(struct Player *p, int board[HEIGHT][WIDTH]){
	
	if(p->y==TUNNEL_Y && p->x == WIDTH-1 && p->dx == 1){
		p->dx = 1;
		p->dy = 0;
		p->x = 0;
	}
	if(p->y==TUNNEL_Y && p->x==0 && p->dx==-1){
		p->dx = -1;
		p->dy =0;
		p->x = WIDTH;
	}
	
	
	if(board[p->y + p->dy][p->x + p->dx]==WALL){
		p->dx = 0;
		p->dy = 0;
	}	
	
}

void update_player(struct Player *p){
	p->x = p->x + p->dx;
	p->y = p->y + p->dy;

}



