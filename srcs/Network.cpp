// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Network.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 09:41:14 by sdurr             #+#    #+#             //
/*   Updated: 2015/06/28 18:06:37 by sdurr            ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Network.hpp"

Network::Network( void ) {

}

Network::~Network( void ) {

}

void Network::setNetwork(std::string str )
{
	size_t position = 0;
	if ((position = str.find("Networks", position)) != std::string::npos)
	{ 
		_Network = str;
		position = 0;
		while (( position = _Network.find("Networks: packets:", position) != std::string::npos ))
		{
			_Network.replace( position - 1, 19, "");
			position += 7;
		}
	}
	size_t i = 0;
	while (_Network[i]  && !isdigit(_Network[i]))
		i++;
	std::string s = "";
	while (isdigit(_Network[i]) && i != _Network.size())
		s += _Network[i++];
	this->_in = s;
	s = "";
	while (++i != _Network.size() && isdigit(_Network[i]))
		s += _Network[i];
	this->_in2 = s;
	while (i != _Network.size() && !isdigit(_Network[i]))
		i++;
	s = "";
	while (isdigit(_Network[i]) && i != _Network.size())
		s += _Network[i++];
	this->_out = s;
	s = "";
	while (++i != _Network.size() && isdigit(_Network[i]))
		s += _Network[i];
	this->_out2 = s;
}

char const * Network::getNetwork( void )
{
	return this->_Network.c_str();
}

void		Network::displayGraph(Window *w)
{
    size_t col = w->getWidh() / 2;
    size_t row = w->getHigh() / 4 - 3;
    
    delwin(_subw);
    delwin(_subw2);
    _subw = newwin(row, col / 2,  (3 * row) + 11, 1);
    _subw2 = newwin(row, col / 2,  (3 * row) + 11, col / 2);
    wbkgd(_subw, COLOR_PAIR(4));
    wbkgd(_subw2, COLOR_PAIR(4));
    box(_subw, ACS_VLINE, ACS_HLINE);
    box(_subw2, ACS_VLINE, ACS_HLINE);
    size_t j = 0;
    while (++j <= 2)
    {
    	std::string in = (j == 1) ? _in : _out; 
    	std::string in2 = (j == 1) ? _in2 : _out2;
    	WINDOW *	subw =  (j == 1) ? _subw : _subw2;
    	std::list<float>::const_iterator it = _lst.begin();

    	if (j == 1)
    	{
    		_lst.push_front(((atof(in.c_str()) / (1092 * 1092)) / (atof(in2.c_str()))) * 100);
    		while(_lst.size() > col / 2 - 3)
    			_lst.pop_back();
    	}
    	else
    	{
    		_lst2.push_front(((atof(in.c_str()) / (1092)) / (atof(in2.c_str()))) * 100);
    		it = _lst2.begin();
    		while(_lst2.size() > col / 2 - 3)
    			_lst2.pop_back();
    	}
    	size_t i = 3;
    	
		while (it != _lst.end() && it != _lst2.end())
		{
			float  p = ((*it / 100.0) * (float)(row)) ;
			size_t t = row - p ;
			while (t != row)
			{
				if ((3 * t) < row)
					wattron(subw, COLOR_PAIR(3));
				else if ((2.5 * t) < row)
					wattron(subw, COLOR_PAIR(2));
				else
					wattron(subw, COLOR_PAIR(1));
				mvwprintw(subw, t++, i, " ");
				if ((3 * t) < row)
					wattroff(subw, COLOR_PAIR(3));
				else if ((2 * t) < row)
					wattroff(subw, COLOR_PAIR(2));
				else
					wattroff(subw, COLOR_PAIR(1));
			}
    		it++;
    		i++;
    	}
    	wrefresh(subw);
    }
}
