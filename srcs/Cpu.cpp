// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cpu.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 09:37:04 by sdurr             #+#    #+#             //
/*   Updated: 2015/06/28 18:05:37 by sdurr            ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Cpu.hpp"
#include <sys/sysctl.h>


Cpu::Cpu( void )
{
	FILE * ram;
	char buf[50];

	if ((ram = popen("sysctl machdep.cpu.brand_string", "r")))
	{
		fgets (buf , 50 , ram);
		_cpuname = std::string(buf);
		_cpuname.replace(0, strlen("machdep.cpu.brand_string: "), "");
		pclose(ram);
	}
}

Cpu::~Cpu( void )
{
}

void Cpu::setCpu(std::string str)
{
	unsigned long position = 0;

	if ((position = str.find("CPU", position)) != std::string::npos)
		_cpu = str;

	std::string sTmp1;

    sTmp1 = _cpu;

    size_t i = 0;
    while (sTmp1[i]  && !isdigit(sTmp1[i]))
		i++;
	std::string s = "";
	while ((isdigit(sTmp1[i]) || sTmp1[i] == '.')  && i != sTmp1.size())
		s += sTmp1[i++];

	this->_u = atof(s.c_str());
	s = "";
	while (i != sTmp1.size() && !isdigit(sTmp1[i]))
		i++;
	s = "";
	while ((isdigit(sTmp1[i]) || sTmp1[i] == '.')  && i != sTmp1.size())
		s += sTmp1[i++];
	this->_s = atof(s.c_str());
	while (i != sTmp1.size() && !isdigit(sTmp1[i]))
		i++;
	s = "";
	while ((isdigit(sTmp1[i]) || sTmp1[i] == '.')  && i != sTmp1.size())
		s += sTmp1[i++];
	this->_i = atof(s.c_str());
}

char const * Cpu::getCpu( void )
{
	return this->_cpu.c_str();
}

char const * Cpu::getCpuName( void )
{
	return this->_cpuname.c_str();
}

void		Cpu::displayGraph(Window *w)
{
    size_t col = w->getWidh() / 2;
    size_t row = w->getHigh() / 4 - 3;

    delwin(_subw);
    delwin(_subw2);
    delwin(_subw3);
    _subw = newwin(row, col / 3,  (2 * row) + 11, col);
    _subw2 = newwin(row, col / 3,  (2 * row) + 11, col + col / 3);
    _subw3 = newwin(row, col / 3,  (2 * row) + 11,  col +  2 * col / 3 );
    wbkgd(_subw, COLOR_PAIR(4));
    wbkgd(_subw2, COLOR_PAIR(4));
    wbkgd(_subw3, COLOR_PAIR(4));
    box(_subw, ACS_VLINE, ACS_HLINE);
    box(_subw2, ACS_VLINE, ACS_HLINE);
    box(_subw3, ACS_VLINE, ACS_HLINE);
    int j = 0;
    while (++j <= 3)
    {
    	float in = ((j == 1) ? _u : ((j == 2) ? _s : _i));
		(void)in;

    	WINDOW *	subw =  ((j == 1) ? _subw : ((j == 2) ? _subw2 : _subw3));
    	std::list<float>::const_iterator it = _lst.begin();

    	if (j == 1)
    	{
    		_lst.push_front(_u);
    		while(_lst.size() > col / 3 - 2)
    			_lst.pop_back();
    	}
    	else if (j == 2)
    	{
    		_lst2.push_front(_s);
    		it = _lst2.begin();
    		while(_lst2.size() > col / 3 - 2)
    			_lst2.pop_back();
    	}
    	else
    	{
    		_lst3.push_front(_i);
    		it = _lst3.begin();
    		while(_lst3.size() > col / 3 - 2)
    			_lst3.pop_back();
    	}
    	int i = 2;

		while (it != _lst.end() && it != _lst2.end() && it != _lst3.end())
		{
			float  p = (*it / 100.0) * row;
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
