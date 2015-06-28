// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: karakhirn <marvin@42.fr>                   +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/26 21:17:58 by karakhirn         #+#    #+#             //
//   Updated: 2015/06/28 14:06:42 by sdurr            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sys/utsname.h>
#include <fstream>


#include "Info.hpp"
#include "Ncurse.hpp"

void		sfml(void);
int main (int ac, char **av)
{

	int i = 0;
	if (ac == 1) {
		std::cout << " Please chose ncurse or sfml" << std::endl;
		return 0;
	}
	if (ac > 2)
	{
		std::cout << " Please chose ncurse or sfml" << std::endl;
		return 0;
	}
	if (strcmp(av[1], "ncurse") == 0){
		Ncurse * win = new Ncurse;
		win->display();
		i = 1;
		delete win;

	}
	else if (strcmp(av[1], "sfml") == 0) {
		sfml();
		i = 2;
	}
	while (1) {
		if (i == 1) {
			sfml();
			i = 2;
		}
		else {
			Ncurse * win = new Ncurse;
			win->display();
			i = 1;
			delete win;
		}
	}
	return 0;
}
