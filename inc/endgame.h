#ifndef ENDGAME_H
#define ENDGAME_H

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <pthread.h>

typedef struct s_trail {
    int y;
    double start;
    double end;
    int speed;
}t_trail;

typedef struct s_player {
	int y;
	int x;
	char *body[5];
} player;

typedef struct s_enemy {
	int y;
	int x;
//	int alive;
	char *e_body[5];
//	char direction;
//	int pr, pc;
} enemy;

typedef struct s_shoot {
	int y;
	int x;
	int active;
	char ch;
} p_shoot;

char *mx_hello(int max_y, int max_x, char *name);
int mx_menu(int max_y, int max_x);
void mx_namegame(int max_y, int max_x);
int mx_info(int max_y, int max_x);
t_trail *generate_trail(int y);
void draw_trail(t_trail *trail, int x, int y, char arr[x][y]);
void matrix_rain();
void delay(int number_of_seconds);
void wake_up_neo();
int mx_strlen(const char *s);

#endif
