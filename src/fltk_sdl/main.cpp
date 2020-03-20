/*
    Copyright 2016-2020 Arisotura

    This file is part of melonDS.

    melonDS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS. If not, see http://www.gnu.org/licenses/.
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include <FL/Fl.h>
#include <FL/Fl_Window.h>
#include <FL/Fl_Menu.h>
#include <FL/Fl_Menu_Bar.h>

#include "main.h"

#include "../version.h"


MainWindow::MainWindow(int w, int h)
    : Fl_Window(w, h, "melonDS FLTK")
{
    Fl_Menu_Bar* mb = new Fl_Menu_Bar(0, 0, w, 30);

    Fl_Menu_Item menu[] =
    {
        {"File", 0, NULL, NULL, FL_SUBMENU},
            {"Open ROM...", 0, NULL, NULL, FL_MENU_DIVIDER},
            {"Quit",        0, OnQuit, this, 0},
            {0},

        {0}
    };

    mb->copy(menu);
    add(mb);
}

MainWindow::~MainWindow()
{
    // heh
}

void MainWindow::OnQuit(Fl_Widget* w, void* _win)
{
    Fl_Window* win = (Fl_Window*)_win;
    win->hide();
}


int main(int argc, char** argv)
{
    srand(time(NULL));

    printf("melonDS " MELONDS_VERSION "\n");
    printf(MELONDS_URL "\n");

    printf("welcome to the fancypants FLTK version\n");
    printf("also Arisotura is a lazy fuck\n");

    //Fl::scheme("plastic");

    Fl_Window* win = new MainWindow(256, 384);

    win->end();
    win->show(argc, argv);

    return Fl::run();
}
