#include <stdio.h>
#include <ncurses.h>
#include <curl/curl.h>
int main()
{
    char username[100];
    CURL *curl;
    CURLcode res;
  
	initscr();			/* Start curses mode 		  */
	printw("Welcome to gitterLite!!!\n");	/* Print Hello World		  */
	printw("Log into gitter....\n");
    printw("Username...\n");
    refresh();			/* Print it on to the real screen */
	getstr(username);			/* Wait for user input */
	erase();
    printw("Hello %s ... I would log you in ... but that is not implemented..", username);
    refresh();

    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
        /*example.com is redirected, so we tell libcurl to follow reddirection*/
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        /*Don't be a messy child*/
        curl_easy_cleanup(curl);
    }
    getch();
    endwin();			/* End curses mode		  */

	return 0;
}
