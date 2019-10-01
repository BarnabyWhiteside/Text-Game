#include <stdio.h>      //code adaptedfrom ncurses website
#include <ncurses.h>
#include <string.h>
#include <menu.h>
#include <stdlib.h>           // added for exit() function
#include <cstring>
#include <string>

char* damageMenu(const char welcome[])    //menu to show descriptions
{
    /* Commandline argument currently unused */
    int argc;
    char **argv;
    (void) argc;
    (void) argv;

    int i, c;
    (void) c;                       // c is currently unused
    //char welcome[]="Generic Adventure Game";
    int time, dlug; //value of terminal length and time

    erase();
    initscr(); //Initialisation of ncurses and colours
    raw();
    noecho();
    keypad(stdscr, TRUE);

    /* Test to see if terminal has colours */
    if (has_colors() == false) {
        fail("Colours unavailable\n");
    }

    if (start_color() != OK) {
        fail("Unable to start colours\n");
    }

    init_pair(1, COLOR_RED, COLOR_BLACK); //colour selection

    getmaxyx(stdscr, time, dlug); //defining the size of the terminal
    move(time/2, (dlug-strlen(welcome))/2); //we move the cursor to the center (so that it prints nicely)
    attron(COLOR_PAIR(1)); //activate colours
    printw(welcome); //print welcome
    attroff(COLOR_PAIR(1));//we deactivate the colours
    refresh();//refresh (otherwise it won't display)
    WINDOW * menuwin=newwin(7, dlug-12, time-9, 6); //we define and create a 'window'
    box(menuwin, 0, 0);
    refresh();//we define and refresh again to make the window appear
    wrefresh(menuwin);//we refesh the window itself
    keypad(menuwin, TRUE);//enable the operation of the keyboard

    char *options[] = {
        "Press Enter to continue",
    };
    int choice;
    int select=0;

    while(1)//loop to create a menu when highlighting selected item
    {
        for(i = 0; i < 1; i++) {
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
}
