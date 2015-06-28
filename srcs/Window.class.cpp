// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/21 17:35:03 by sdurr             #+#    #+#             //
//   Updated: 2015/06/27 19:04:34 by sdurr            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Window.class.hpp"


Window::Window( void )
{
    std::cout << "Initialisation de la fenetre !" << std::endl;
    if (initscr())
    {
        start_color();
		init_color(COLOR_YELLOW, 500, 400, 100);
        init_pair(1, COLOR_GREEN, COLOR_GREEN);
        init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(3, COLOR_RED, COLOR_RED);
        init_pair(4, COLOR_MAGENTA, COLOR_WHITE);
        init_pair(5, COLOR_CYAN, COLOR_BLUE);
        noecho();
        cbreak();
		timeout(50);
        keypad(stdscr, TRUE);
        bkgd(COLOR_PAIR(5));
        refresh();
        this->setSize();
        this->_win = newwin(this->_h , this->_w, 0, 0);
		wbkgd(this->_win,COLOR_PAIR(5));
        wrefresh(this->_win);
    }
    else
    {
        std::cout << " : Initialisation failed." << std::endl;
        std::exit(0);
    }
}

Window::~Window()
{
    this->exit();
    std::cout << "Ncurses perfectly close" << std::endl;
}

void    Window::setSize()
{
    getmaxyx(stdscr, _h, _w);
}

 WINDOW *    Window::getWin()
 {
    return (this->_win);
 }

int         Window::getWidh()
{
    return (this->_w);
}

int         Window::getHigh()
{
    return (this->_h);
}

void    Window::reSize()
{
    this->setSize();
    wresize(this->_win, this->_h, this->_w);
    Window::i = 0;
}

void    Window::exit()
{
    delwin(this->_win);
    endwin();
}

int     Window::i = 0;


