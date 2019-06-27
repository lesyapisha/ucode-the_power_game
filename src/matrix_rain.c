//matrix_rain.c
#include "endgame.h"

void matrix_rain(){
	//NCURSES START
    WINDOW *win = initscr();
    
    cbreak();
    noecho();

    //get width and height of terminal window
    int x, y, i, k;
    getmaxyx(win, x, y);
    //y - number of columns, x - number of rows
    
    


    t_trail trails[y];
    for (k = 0; k < y; k++) {
        trails[k] = *generate_trail(k);
    }
    
    curs_set(0);
    
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    

    char arr[x][y];
    for(i = 0; i < x; i++){
        for (k = 0; k < y; k++) {
            arr[i][k] = 48 + (rand() % 78);
        }
    }
    
    //create box over matrix rain
//    WINDOW *overbox = subwin(win, 9, x - 6, y / 2, 3);
    char *phrase = "Game Over";
    int length = mx_strlen(phrase);
    int box_length = length + 2;
    int start_y = (y - box_length) / 2;
    int start_x = (x - 3) / 2;
    WINDOW *overbox = subwin(win, 3, box_length, start_x, start_y);
    
//    refresh();
//    wrefresh(overbox);
    nodelay(stdscr, TRUE);
    int ch;
    while ((ch = getch()) == ERR) {
        clear();
        for (k = 0; k < y; k++) {
            draw_trail(&trails[k], x, y, arr);
        }
        wclear(overbox);
        wattron(overbox, COLOR_PAIR(3));
        mvwprintw(overbox, 1, 1, phrase);
        wattroff(overbox, COLOR_PAIR(3));
        refresh();
        wrefresh(overbox);
        usleep(100000);
    }
    
//    getch();
    endwin();
    //NCURSES END
}
