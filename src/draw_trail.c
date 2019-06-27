//draw_trail.c
#include "endgame.h"

void draw_trail(t_trail *trail, int x, int y, char arr[x][y]) {
    int i;
     trail->start = trail->start + (trail->speed) / (double) 10;
     trail->end = trail->end + (trail->speed) / (double) 10;

    attron(COLOR_PAIR(1));
    for (i = trail-> end; i < trail-> start - 1; i++) {
        mvaddch(i % x, trail->y, arr[i % x][trail->y]);
    }
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    mvaddch(((int) trail->start) % x, trail->y, arr[((int)trail->start) % x][trail->y]);
    attroff(COLOR_PAIR(2));
}
