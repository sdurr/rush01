// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cpu.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 09:36:23 by sdurr             #+#    #+#             //
//   Updated: 2015/06/28 17:51:03 by sdurr            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CPU_H
# define CPU_H

#include <iostream>
#include <ncurses.h>
#include <list>
#include "Window.class.hpp"
#include "IMonitorModule.hpp"

class Cpu  : public IMonitorModule
{
	public:
		Cpu( void );
		~Cpu( void );

		void setCpu(std::string);
		char const * getCpu( void );
		char const * getCpuName( void );
		void	displayGraph(Window *);

	private:
		std::string _cpuname;
		std::string _cpu;
		float _u;
    	float _s;
    	float _i;
    	std::list<float> _lst;
		std::list<float> _lst2;
		std::list<float> _lst3;
		WINDOW * _subw;
		WINDOW * _subw2;
		WINDOW * _subw3;

	Cpu(Cpu const & src);
	Cpu & operator=(Cpu const & rhs);
};

#endif
