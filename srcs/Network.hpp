// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Network.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 09:40:38 by sdurr             #+#    #+#             //
//   Updated: 2015/06/28 17:52:19 by sdurr            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NETWORK_H
# define NETWORK_H

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <ncurses.h>
#include <list>
#include <iostream>
#include <stdlib.h>
#include "Window.class.hpp"
#include "IMonitorModule.hpp"


class Network  : public IMonitorModule {
public :
	Network( void );
	~Network( void );
	void setNetwork(std::string);
	char const * getNetwork( void );
	virtual void	displayGraph(Window *);

private:
	std::string	_in;
	std::string	_in2;
	std::string	_out;
	std::string	_out2;
	std::string _Network;
	std::list<float> _lst;
	std::list<float> _lst2;
	WINDOW * _subw;
	WINDOW * _subw2;
	Network( Network const & src);
	Network &  operator=(Network const & rhs);
};

#endif
