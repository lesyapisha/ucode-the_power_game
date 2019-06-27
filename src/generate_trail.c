//generate_trail.c
#include "endgame.h"

t_trail *generate_trail(int y) {
    t_trail * trail = malloc(sizeof(t_trail));
    trail->y = y;
    trail->start = rand() % 25;
    trail->end = trail->start - rand() % 15;
    trail->speed = 1 + (rand() % 3);
    return trail;
}
