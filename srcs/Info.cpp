// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Info.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 09:36:01 by sdurr             #+#    #+#             //
//   Updated: 2015/06/27 19:49:07 by sdurr            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Info.hpp"

Info::Info( void ) : _nb(5)
{
	struct utsname info;
	struct passwd *infoP;

	uname(&info);
	infoP = getpwuid(getuid());

	this->_hostName = std::string("HostName : ");
	this->_userName = std::string("UserName : ");
	this->_Os = std::string("Os : ");
	this->_osVersion = std::string("");

	this->_hostName.append(std::string(info.nodename));
	this->_userName.append(std::string(infoP->pw_name));
	this->_Os.append(std::string(info.sysname));
	this->_osVersion.append(std::string(info.version));
	int position = 0;
	position = _osVersion.find(":", position);
	_osVersion.resize( position);

	time_t t;
	struct tm dat;
	char form[32];

	time(&t);
	dat = *localtime(&t);
	strftime(form, 32, "%Y-%m-%d %H:%M", &dat);

	_dateHour = std::string("Date : ");
	_dateHour.append(std::string(form));
}

Info::~Info( void ) {

}

void Info::setDate( void ){
	time_t t;
	struct tm dat;
	char form[32];

	time(&t);
	dat = *localtime(&t);
	strftime(form, 32, "%Y-%m-%d %H:%M", &dat);

	this->_dateHour = std::string("Date : ");
	this->_dateHour.append(std::string(form));
}

int Info::getSize( void ) const {
	return this->_nb;
}
char const *  Info::getHost( void )  const {

	return this->_hostName.c_str();
}

char const	*  Info::getUser( void ) const {
	return this->_userName.c_str();
}

char const	*  Info::getOs( void ) const {
	return this->_Os.c_str();
}

char const	*  Info::getOsVersion( void ) const {
	return this->_osVersion.c_str();
}

char const	*  Info::getDate( void )  {
	setDate();
	return this->_dateHour.c_str();
}
