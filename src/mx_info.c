#include "endgame.h"


void dddelay(int number_of_seconds);

int  mx_info(int max_y, int max_x) 
{
	initscr();
	start_color();
	cbreak();
	noecho();
	curs_set(0);

	init_pair(1, COLOR_RED, COLOR_BLACK);

	char *str[23];

	str[0]  = "*** THE POWER GAME ***";
    str[1]  = "How to play:";
    str[2]  = "1. Clear your mind.";
    str[3]  = "2. Avoid enemies";
    str[4]  = "3. Use key <== to strafe left OR ==> to strafe right";
    str[5]  = "4. Don`t forget to continue your education after 2 minuties of gaming ;)";
    str[6]  = "\n";
    str[7]  = "\n";
    str[8]  = "\n";
    str[9]  = "\n";
    str[10] = "\n";
    str[11] = "Developed by ddikhtiar, snefedov, ademicheva, opisha, skhorishch, onechaiev";
    str[12] = "";
    str[13] = "(c) uCode. Are you born2code?";
    str[14] = "\n";
    str[15] = "";
    str[16] = "";
    str[17] = "";
    str[18] = "";
    str[19] = "";
    str[20] = "";
    str[21] = "-> Press <<R>> to return to main menu";
    str[22] = NULL;
     
	attron(COLOR_PAIR(1));
	attron(A_BOLD | A_BOLD);
	for (int j = 0; str[j] != NULL; j++) {
		mvprintw(max_y /2 + j -12, max_x /2  - 39, str[j]);
		dddelay(100);
		refresh();
	} 
	attroff(COLOR_PAIR(1));
	attroff(A_BOLD | A_BOLD);
    
    
	int count = getch();
	//if (count == 114)
		return 114;


	endwin();
	refresh();
	return count;
}

void dddelay(int number_of_seconds) {
	int milli_seconds = 1000 *number_of_seconds;
	clock_t start_time = clock();
	while(clock() < start_time + milli_seconds) {
		;
	}
}
