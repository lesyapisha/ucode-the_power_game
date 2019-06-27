#include "endgame.h"

void mx_namegame(int max_y, int max_x); 

int main () {

		initscr();

		int higth, width, start_y, start_x;
		int max_y, max_x;

		getmaxyx(stdscr, max_y, max_x);

		higth = max_y - 2;
		width = max_x - 4;
		start_y = 1;
		start_x = 2;

		char name[20];

	mx_namegame(max_y, max_x);  //statr program
	clear();
	while (1) {
        int x = mx_menu(max_y, max_x);
        clear();
        refresh();
        echo();
        if (x == 5)
            mx_hello(max_y, max_x, name);
        if (x == 6) {
            endwin();
            return 0;
        }
        if (x == 4)
        {
            int y = mx_info(max_y, max_x);
            clear();
            echo();
            if (y == 114) {
                int u = mx_menu(max_y, max_x);
                clear();
                echo();
                if (u == 5) {
                    clear();
                    refresh();
                    echo();
                    mx_hello(max_y, max_x, name);
                }
                if (u == 6) {
                    endwin();
                    return 0;
                }
                if (u == 4) {
                    int z = mx_info(max_y, max_x);
                    clear();
                    echo();
                    if (z == 114) {
                        int z = mx_menu(max_y, max_x);
                        if (z == 5) {
                            clear();
                            refresh();
                            echo();
                            mx_hello(max_y, max_x, name);
                        }
                        if (z == 6) {
                            endwin();
                            return 0;
                        }
                    }
                }
            }
        }
        noecho();
        clear();
        refresh();
        
        WINDOW * win = newwin(higth, width, start_y, start_x);
        refresh();
        curs_set(0);

        box(win, 0, 0);
        mvwprintw(win, 2, 4, "NAME: -=( %s )=-", name);
        wrefresh(win);

        keypad(stdscr, true);

        player tank;
        tank.body[0] = " _____ ";
        tank.body[1] = "|  |  |";
        tank.body[2] = "| [_] |";
        tank.body[3] = "| <=> |";
        tank.body[4] = "|_____|";

        tank.y = max_y - 8;
        tank.x = (max_x - 7) / 2;

        int count = 0;                
        mvwprintw(win, 2, max_x -20, "Score = %d", count);

        enemy *enemies[3];
        for (int j = 0; j < 3; j++) {
            enemy *octo = malloc(sizeof(enemy));
            octo -> e_body[0] = "| | | | ";
            octo -> e_body[1] = "\\ | | /";
            octo -> e_body[2] = " \\|_|/ ";
            octo -> e_body[3] = " /ooo\\ ";
            octo -> e_body[4] = "(ooooo) ";
            enemies[j] = octo;
        }

        for (int i = 0; i < 5; i++) {
            mvwaddstr(win, tank.y + i, tank.x, tank.body[i]);
        }
        wrefresh(win);

        for (int j = 0; j < 3; j++) {
            enemies[j] -> x = (rand() % (max_x - 17)) + 5;
            enemies[j] -> y = -(rand() % 10) - 5;
        }
        
        int on = 1;
        while (on) {

            timeout(5);
            for (int j = 0; j < 3; j++) {

                if (enemies[j] ->y <= max_y + 3) {
                    for (int i = 0; i < 5; i++) {
                        if (enemies[j] -> y - i >= 4 && enemies[j] ->y - i <= max_y - 4) {
                            mvwaddstr(win, enemies[j] ->y - i , enemies[j] ->x, enemies[j] ->e_body[4 - i]);
                        }
                        if (enemies[j] ->y >= 9 && enemies[j] ->y - i <= max_y - 3) {
                            mvwaddstr(win, enemies[j] ->y - 5, enemies[j] ->x, "       ");
                        }
                        wrefresh(win);
                    }
                    enemies[j] ->y++;
                }
                else {
                    enemies[j] ->x = (rand() % (max_x - 17)) + 5;
                    enemies[j] ->y = 4;
                count++;
                mvwprintw(win, 2, max_x -20, "Score = %d", count);
                wrefresh(win);  
                }
            }

            for (int j = 0; j < 5; j++) {
                mvwaddch(win, tank.y + j, tank.x, ' ');
                mvwaddch(win, tank.y + j, tank.x + 6, ' ');
            }
            switch (getch()) {
                case KEY_LEFT:
                    --tank.x;
                    break;
                case KEY_RIGHT:
                    ++tank.x;
                    break;
            }
            if (tank.x > max_x - 12)
                tank.x = max_x - 12;
            else if (tank.x < 1)
                tank.x = 1;

            for (int i = 0; i < 5; i++) {
                mvwaddstr(win, tank.y + i, tank.x, tank.body[i]);
                wrefresh(win);
            }
            for (int j = 0; j < 3; j++) {
                if (enemies[j] -> y - 4 >= tank.y) {
                    if ((enemies[j] -> x >= tank.x && enemies[j] ->x <= tank.x + 6)
                        || (enemies[j] ->x + 7 >= tank.x && enemies[j] ->x + 7 <= tank.x + 6)) {
                        on = 0;
                        keypad(stdscr, false);
                        matrix_rain();
                        clear();
                        refresh();

                        break;
                    }
                }
            }
		
            wrefresh(win);
            usleep(30000);

        }
        
        for (int j = 0; j < 3; j++) {
            free(enemies[j]);
        }
        getch();
        endwin();
    }
}

