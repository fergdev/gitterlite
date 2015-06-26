#include <ncurses.h>

int main()
{
    char username[100];

	initscr();			/* Start curses mode 		  */
	printw("Welcome to gitterLite!!!\n");	/* Print Hello World		  */
	printw("Log into gitter....\n");
    printw("Username...\n");
    refresh();			/* Print it on to the real screen */
	getstr(username);			/* Wait for user input */
	erase();
    printw("Hello %s ... I would log you in ... but that is not implemented..", username);
    refresh();
    getch();
    endwin();			/* End curses mode		  */

	return 0;
}
