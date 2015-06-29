#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <curl/curl.h>
void gitterLogin();
char *clientCode;
char *clientSecret;

int main(int argc, char *argv[])
{
    int index; 
    int opt;
    while((opt = getopt(argc, argv, "cs")) != -1){

        switch(opt)
        {
            case'c':clientCode=optarg;break;//client code
            case's':clientSecret=optarg;break;//client secret
            defaut:
                fprintf(stderr, "Usage %s [-cs]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }    
    for (index = optind; index < argc; index++)
    {
        printf("Non-option argument %s\n", argv[index]);
    }
    gitterLogin(); 
    return 0;
}
void gitterLogin()
{
    char *clientId;
    char *clientSecret;
    char *code;
    char *redirectURI;
    char *username[100];
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
        curl_easy_setopt(curl, CURLOPT_URL, "https://gitter.im/login/oauth/token");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, ("client_id=%s&client_secret=%s&code=%s&grant_type=authorization_code&redirect_uri=%s",clientId, clientSecret,code,redirectURI));



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


}
