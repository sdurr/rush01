// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ram.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 09:39:24 by sdurr             #+#    #+#             //
/*   Updated: 2015/06/28 18:07:43 by sdurr            ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Ram.hpp"
#include "Ncurse.hpp"
Ram::Ram( void ) {
	FILE* pipe = popen("sysctl hw.ncpu", "r");
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    result.replace(0, strlen("hw.ncpu: "), "");
    _ncpu = result;
}

Ram::~Ram( void ) {
    
}

void Ram::setMemUsed( std::string str )
{
    size_t position = 0;
    size_t i = 0;
    size_t j;
    
    if ((position = str.find("PhysMem", position)) != std::string::npos)
    {
        _memUsed = str;
        position = 0;
        while (( position = _memUsed.find("PhysMem: ", position) != std::string::npos ))
        {
            _memUsed.replace( position - 1, 9, "");
            
        }
        char tmp[5];
        j = 0;
        i = 0;
        while ((str[i] < 48 && str[i]) || (str[i] > 57 && str[i]))
            i++;
        while ((str[i] >= 48 && str[i] <= 57 && str[i]))
            tmp[j++] = str[i++];
        tmp[j] = '\0';
        _used = atoi(tmp);
        j = 0;
        while ((str[i] < '0' && str[i]) || (str[i] > 57 && str[i]))
            i++;
        while ((str[i] >= '0' && str[i] <= 57 && str[i]))
            i++;
        while ((str[i] < '0' && str[i]) || (str[i] > 57 && str[i]))
            i++;
        while ((str[i] >= '0' && str[i] <= 57 && str[i]))
            tmp[j++] = str[i++];
        tmp[j] = '\0';
        
        _unused = atoi(tmp);
    }
}

int Ram::getPourCent( void ) const {
    float total;
    float P;
    
    total = this->_used + this->_unused;
    P = (this->_used / total) * 100;
    return P;
}

char const * Ram::getNcpu( void ) const {
		
		return _ncpu.c_str();
}

char const * Ram::getMemUsed( void ) {
    return this->_memUsed.c_str();
}

char const * Ram::getPourCentS( void ) {
    std::string i = std::to_string(getPourCent());
    return i.c_str();
}

void		Ram::displayGraph(Window *w)
{
    size_t col = w->getWidh() / 2;
    size_t row = w->getHigh() / 4 - 3;
    
    delwin(_subw);
    _subw = newwin(row, col, row + 5, 1);
    wbkgd(_subw, COLOR_PAIR(4));
    box(_subw, ACS_VLINE, ACS_HLINE);
    
    _lst.push_front(getPourCent());
    std::list<float>::const_iterator it = _lst.begin();
    size_t i = 3;
    while(_lst.size() > col - 3)
    	_lst.pop_back();
	while (it != _lst.end())
	{
		float  p = (*it * (float)(row) )/ 100.0 ;
		size_t t = row - p ;
		while (t != row)
		{
			if ((3 * t) < row)
				wattron(_subw, COLOR_PAIR(3));
			else if ((2.5 * t) < row)
				wattron(_subw, COLOR_PAIR(2));
			else
				wattron(_subw, COLOR_PAIR(1));
			mvwprintw(_subw, t++, i, " ");
			if ((3 * t) < row)
				wattroff(_subw, COLOR_PAIR(3));
			else if ((2 * t) < row)
				wattroff(_subw, COLOR_PAIR(2));
			else
				wattroff(_subw, COLOR_PAIR(1));
		}
    	it++;
    	i++;
    }
    wrefresh(_subw);
    
}
