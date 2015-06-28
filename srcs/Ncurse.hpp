// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ncurse.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:46:58 by sdurr             #+#    #+#             //
//   Updated: 2015/06/28 17:53:27 by sdurr            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NCURSE_H
#define NCURSE_H

# include <signal.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <ncurses.h>
# include <iostream>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include "Window.class.hpp"
#include "IMonitorDisplay.hpp"


class Ncurse  : public IMonitorDisplay
{
public:
	Ncurse( void );
	~Ncurse( void );

	virtual void display( void );

	void	reSize();
	std::string	getInfos();

	WINDOW *mem;
	WINDOW *cp;
	WINDOW *ne;


private:
	Window * _win;
	Ncurse( Ncurse const &);
	Ncurse & operator=(Ncurse const &);
};


#endif

