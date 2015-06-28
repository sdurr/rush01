// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ram.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 09:38:55 by sdurr             #+#    #+#             //
//   Updated: 2015/06/28 17:51:39 by sdurr            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RAM_H
# define RAM_H

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <list>
#include "Window.class.hpp"
#include "IMonitorModule.hpp"


class Ram : public IMonitorModule
{
public:
	Ram( void );
	~Ram( void );

	void setMemUsed( std::string);
	char const * getMemUsed( void );
	char const * getMemUnused( void );
	char const * getPourCentS( void );
	int getPourCent( void ) const;
	char const * getNcpu( void ) const;
	virtual void	displayGraph(Window *);

private:
	std::string _memUsed;
	std::string _memUnused;

	int _used;
	int _unused;
	float _porcent;
	std::list<float> _lst;
	WINDOW * _subw;
	std::string		_ncpu;
	Ram( Ram const & src);
	Ram & operator=( Ram const & rhs);
};

#endif
