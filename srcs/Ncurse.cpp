// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ncurse.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:49:51 by sdurr             #+#    #+#             //
/*   Updated: 2015/06/28 18:08:00 by sdurr            ###   ########.fr       */
//                                                                            //
// ************************************************************************** //


#include <fstream>
#include "Ncurse.hpp"
#include "Ram.hpp"
#include "Info.hpp"
#include "Cpu.hpp"
#include "Network.hpp"
#include <cstdio>
#include <typeinfo>
#include <signal.h>
  #include <unistd.h>
#include <list>
#include <string>

Ncurse::Ncurse( void ) {

	this->_win = new Window;

	curs_set(0);
	int col = _win->getWidh() / 2;
	int row = _win->getHigh() / 4;
	mem = newwin(row, col , row, 1);
	cp = newwin(row , col,  2 * row , col);
	ne = newwin(row , col, 3 * row, 1);

	wbkgd(mem,COLOR_PAIR(4));
	wrefresh(mem);
	wbkgd(cp,COLOR_PAIR(4));
	wrefresh(cp);
	wbkgd(ne,COLOR_PAIR(4));
	wrefresh(ne);
}

void Ncurse::display()
{
	Info info;
	int key;
	Ram ram;
	Network net;
	Cpu cpu;

	while (1)
	{
		int h, w;
		getmaxyx(stdscr, h, w);
		if (h != _win->getHigh() || w != _win->getWidh())
		{
			this->reSize();
    		refresh();
    		Window::i = 0;
		}
		key = getch();
		std::string str = getInfos();
		while (str.size())
		{
			int ps = 0;
			ps = str.find("\n", ps);
			std::string str2 = str.substr(0, ps);
			str.replace(0, ps + 1, "");
			info.setDate();
			ram.setMemUsed(str2);
			net.setNetwork(str2);
			cpu.setCpu(str2);
		}

		mvprintw(1, COLS / 2 - strlen(info.getOs()) / 2 , info.getOs());
		mvprintw(2,1 , info.getUser());
		mvprintw(3,1 , info.getHost());
		mvprintw(5,1 , info.getOsVersion());
		mvprintw(7,1 , info.getDate());
		refresh();

		mvwprintw(mem, 0 ,0, " Memoire:");
		mvwprintw(mem, 1, 1 , ram.getMemUsed());
		if (key == ' ') {
			endwin();
			return ;
		}
		else if (key == 27)
			std::exit(0);
		wrefresh(mem);
		ram.displayGraph(_win);

		mvwprintw(ne, 0,0, "Network:");
		mvwprintw(ne,1,1, net.getNetwork());
		net.displayGraph(_win);
		wrefresh(ne);

		mvwprintw(cp, 0, 0, "CPU:");
		mvwprintw(cp, 1, 1, (char *)cpu.getCpuName());
		mvwaddstr(cp, 2, 1, cpu.getCpu());
		mvwprintw(cp, 3, 1 , "NB CPU : ");
		mvwprintw(cp, 3, 10 , ram.getNcpu());
		cpu.displayGraph(_win);
		wrefresh(cp);


	}
}

void	Ncurse::reSize()
{
	delete _win;
	this->_win = new Window;

	wbkgd(this->_win->getWin(), COLOR_PAIR(2));
	int col = _win->getWidh() / 2;
	int row = _win->getHigh() / 4;
	mem = newwin(row, col , row, 1);
	wbkgd(mem,COLOR_PAIR(4));
	wrefresh(mem);
	cp = newwin(row , col,  2 * row , col);
	wbkgd(cp,COLOR_PAIR(4));
	wrefresh(cp);
	ne = newwin(row , col, 3 * row, 1);
	wbkgd(ne,COLOR_PAIR(4));
	wrefresh(ne);
	refresh();
}

std::string		Ncurse::getInfos()
{
	FILE* pipe = popen("top -l 1 -n 0 ", "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return result;
}


Ncurse::~Ncurse( void ) {

}

