// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   info.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 09:35:08 by sdurr             #+#    #+#             //
//   Updated: 2015/06/27 19:49:14 by sdurr            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INFO_H
# define INFO_H

#include <iostream>
#include <sys/utsname.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <pwd.h>


class Info {
public:
	Info( void );
	~Info( void );


	char const * getHost( void ) const ;
	char const * getUser( void ) const ;
	char const * getOs( void ) const ;
	char const * getOsVersion( void ) const ;
	char const * getDate( void ) ;
	int getSize( void ) const;
	void setDate( void );

private:
	Info &operator=(Info const &);
	Info(Info const &);

	std::string _hostName;
	std::string  _userName;
	std::string  _Os;
	std::string  _osVersion;
	std::string  _dateHour;
	int _nb;
};

#endif
