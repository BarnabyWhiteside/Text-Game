#include <iostream>
#include "libsqlite.hpp"
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <menu.h>
#include <stdlib.h>   

/*code copied from menuFunc.h */

void fail(char *msg) {
    endwin();
    puts(msg);
    exit(EXIT_FAILURE);
}

void print_menu()
{
    
/* Commandline argument currently unused */
    int argc;
    char **argv;
    (void) argc;
    (void) argv;

    int i, c;
    (void) c;                       // c is currently unused
    char welcome[]="Generic Adventure Game";
    int time, dlug; //value of terminal length and time

    initscr(); //Initialisation of ncurses and colours
    raw();
    noecho();
    keypad(stdscr, TRUE);

    /* Test to see if terminal has colours */
    if (has_colors() == false) {
        fail("Colors unavailable\n");
    }

    if (start_color() != OK) {
        fail("Unable to start colors\n");
    }

    //init_pair(1, COLOR_BLUE, COLOR_BLACK); //colour selection

    getmaxyx(stdscr, time, dlug); //defining the size of the terminal
    move(time/2, (dlug-strlen(welcome))/2); //we move the cursor to the center (so that it prints nicely)
    //attron(COLOR_PAIR(1)); //activate colours
    printw(welcome); //print welcome
    //attroff(COLOR_PAIR(1));//we deactivate the colours
    refresh();//refresh (otherwise it won't display)
    WINDOW * menuwin=newwin(7, dlug-12, time-9, 6); //we define and create a 'window'
    box(menuwin, 0, 0);
    refresh();//we define and refresh again to make the window appear
    wrefresh(menuwin);//we refesh the window itself
    keypad(menuwin, TRUE);//enable the operation of the keyboard
    /*end of copied code*/
    
    sqlite::sqlite db("GameDatabaseV0.3");
    auto cur = db.getStatement();
    cur -> set_sql ("SELECT * FROM inventory;");
    cur -> prepare();
    char *options[] = {};
    int choice;
    int select=0;
    while( cur -> step())
        {
            options.push_back(cur -> get_int(0) && " " && cur -> get_int(1));
        }
    
    /*code copied from menuFunc.h*/
    while(1)//loop to create a menu when highlighting selected item
    {
        for(i = 0; i < 5; i++) {
            if(i == select)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, options[i]);
            if (i == select)
                wattroff(menuwin, A_REVERSE);
        }

        choice = wgetch(menuwin);
        switch(choice)
        {
        case KEY_UP:
            select--;
            if(select < 0) select = 0;//prevent going outside the menu
            break;
        case KEY_DOWN:
            select++;
            if(select > 4) select = 4;
            break;
        default:
            break;
        }

        if(choice==10) break;
    }

    //printw("\nThe player has chosen:%s", options[select]);
    refresh();


    /* Wait for user to press enter to exit */
    //getch();

    /* Need to cleanup before exit */
    endwin();


    return options[select];
    /*end of copied code*/
}


int main()
{
    
    print_menu();
    
    return 1;
}