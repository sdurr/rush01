/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sfml.Block.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acivita <acivita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 03:18:04 by acivita           #+#    #+#             */
/*   Updated: 2015/06/28 15:47:56 by acivita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sfml.Block.hpp"

SfmlBlock::SfmlBlock(Info &info, sf::Font *font)
{
	int x = 0;
	int y = 0;
	this->_background.setPosition(x,y);
	this->_background.setSize(sf::Vector2f(400, 315));
	this->_background.setOutlineThickness(0);
	this->_background.setOutlineColor(sf::Color::Black);
	this->_background.setFillColor(sf::Color::White);

	this->_backgroundTitle.setPosition(x + 5,y + 5);
	this->_backgroundTitle.setSize(sf::Vector2f(390, 50));
	this->_backgroundTitle.setOutlineThickness(1);
	this->_backgroundTitle.setOutlineColor(sf::Color::Black);
	this->_backgroundTitle.setFillColor(sf::Color(237,86,89));

	this->_info.setPosition(x + 5,y +60);
	this->_info.setSize(sf::Vector2f(390, 250));
	this->_info.setOutlineThickness(1);
	this->_info.setOutlineColor(sf::Color::Black);
	this->_info.setFillColor(sf::Color(158,212,239));

	this->_title.setPosition(x + 15, y + 0);
	this->_title.setCharacterSize(40);
	this->_title.setString("Informations");
	this->_title.setFont(*font);
	this->_title.setColor(sf::Color::Black);

	this->_info1.setPosition(x + 10, y + 50 + 10);
	this->_info1.setCharacterSize(25);
	this->_info1.setString(info.getHost());
	this->_info1.setFont(*font);
	this->_info1.setColor(sf::Color::Black);

	this->_info2.setPosition(x + 10, y + 100 + 10);
	this->_info2.setCharacterSize(25);
	this->_info2.setString(info.getUser());
	this->_info2.setFont(*font);
	this->_info2.setColor(sf::Color::Black);

	this->_info3.setPosition(x + 10, y + 150 + 10);
	this->_info3.setCharacterSize(25);
	this->_info3.setString(info.getOs());
	this->_info3.setFont(*font);
	this->_info3.setColor(sf::Color::Black);

	this->_info4.setPosition(x + 10, y + 200 + 10);
	this->_info4.setCharacterSize(25);
	this->_info4.setString(info.getOsVersion());
	this->_info4.setFont(*font);
	this->_info4.setColor(sf::Color::Black);

	this->_info5.setPosition(x + 10, y + 250 + 10);
	this->_info5.setCharacterSize(25);
	this->_info5.setString(info.getDate());
	this->_info5.setFont(*font);
	this->_info5.setColor(sf::Color::Black);
	return;
}

SfmlBlock::SfmlBlock(Ram &ram, sf::Font *font)
{
	int x = 0;
	int y = 315;
	this->_background.setPosition(x,y);
	this->_background.setSize(sf::Vector2f(400, 165));
	this->_background.setOutlineThickness(0);
	this->_background.setOutlineColor(sf::Color::White);
	this->_background.setFillColor(sf::Color::White);

	this->_backgroundTitle.setPosition(x + 5,y + 5);
	this->_backgroundTitle.setSize(sf::Vector2f(390, 50));
	this->_backgroundTitle.setOutlineThickness(1);
	this->_backgroundTitle.setOutlineColor(sf::Color::Black);
	this->_backgroundTitle.setFillColor(sf::Color(242,127,70));

	this->_info.setPosition(x + 5,y + 60);
	this->_info.setSize(sf::Vector2f(390, 150));
	this->_info.setOutlineThickness(1);
	this->_info.setOutlineColor(sf::Color::Black);
	this->_info.setFillColor(sf::Color(158,212,239));

	this->_title.setPosition(x + 15, y + 0);
	this->_title.setCharacterSize(40);
	this->_title.setString("Memory");
	this->_title.setFont(*font);
	this->_title.setColor(sf::Color::Black);

	std::string tmp;
	int pos = 0;
	tmp = strdup(ram.getMemUsed());
	pos = tmp.find(",", pos);
	std::string tmp2 = tmp.substr(0, pos + 1);
	this->_info1.setPosition(x + 10, y + 50 + 10);
	this->_info1.setCharacterSize(25);
	this->_info1.setString(tmp2);
	this->_info1.setFont(*font);
	this->_info1.setColor(sf::Color::Black);

	this->_info4.setPosition(x + 10, y + 100 + 10);
	this->_info4.setCharacterSize(25);
	this->_info4.setString(&tmp[pos + 1]);
	this->_info4.setFont(*font);
	this->_info4.setColor(sf::Color::Black);

	this->_info2.setPosition(x + 10, y + 150 + 10);
	this->_info2.setCharacterSize(25);
	this->_info2.setString(ram.getPourCentS());
	this->_info2.setFont(*font);
	this->_info2.setColor(sf::Color::Black);

	this->_info3.setPosition(x + 40, y + 150 + 10);
	this->_info3.setCharacterSize(25);
	this->_info3.setString("% of memory is used.");
	this->_info3.setFont(*font);
	this->_info3.setColor(sf::Color::Black);
	return;
}

SfmlBlock::SfmlBlock(Cpu &cpu, Ram &ram, sf::Font *font)
{
	int x = 0;
	int y = 530;
	this->_background.setPosition(x,y);
	this->_background.setSize(sf::Vector2f(400, 165));
	this->_background.setOutlineThickness(0);
	this->_background.setOutlineColor(sf::Color::White);
	this->_background.setFillColor(sf::Color::White);

	this->_backgroundTitle.setPosition(x + 5,y + 5);
	this->_backgroundTitle.setSize(sf::Vector2f(390, 50));
	this->_backgroundTitle.setOutlineThickness(1);
	this->_backgroundTitle.setOutlineColor(sf::Color::Black);
	this->_backgroundTitle.setFillColor(sf::Color(234,231,167));

	this->_info.setPosition(x + 5,y + 60);
	this->_info.setSize(sf::Vector2f(390, 150));
	this->_info.setOutlineThickness(1);
	this->_info.setOutlineColor(sf::Color::Black);
	this->_info.setFillColor(sf::Color(158,212,239));

	this->_title.setPosition(x + 15, y + 0);
	this->_title.setCharacterSize(40);
	this->_title.setString("Processor");
	this->_title.setFont(*font);
	this->_title.setColor(sf::Color::Black);


	this->_info1.setPosition(x + 10, y + 50 + 10);
	this->_info1.setCharacterSize(25);
	this->_info1.setString(cpu.getCpuName());
	this->_info1.setFont(*font);
	this->_info1.setColor(sf::Color::Black);

	this->_info2.setPosition(x + 10, y + 100 + 10);
	this->_info2.setCharacterSize(18);
	this->_info2.setString(cpu.getCpu());
	this->_info2.setFont(*font);
	this->_info2.setColor(sf::Color::Black);

	this->_info3.setPosition(x + 10, y + 150 + 10);
	this->_info3.setCharacterSize(18);
	this->_info3.setString("# of Cores : ");
	this->_info3.setFont(*font);
	this->_info3.setColor(sf::Color::Black);

	this->_info4.setPosition(x + 115, y + 150 + 10);
	this->_info4.setCharacterSize(25);
	this->_info4.setString(ram.getNcpu());
	this->_info4.setFont(*font);
	this->_info4.setColor(sf::Color::Black);
	return;
}

SfmlBlock::SfmlBlock(Network &network, sf::Font *font)
{
	int x = 0;
	int y = 745;
	this->_background.setPosition(x,y);
	this->_background.setSize(sf::Vector2f(400, 115));
	this->_background.setOutlineThickness(0);
	this->_background.setOutlineColor(sf::Color::White);
	this->_background.setFillColor(sf::Color::White);

	this->_backgroundTitle.setPosition(x + 5, y + 5);
	this->_backgroundTitle.setSize(sf::Vector2f(390, 50));
	this->_backgroundTitle.setOutlineThickness(1);
	this->_backgroundTitle.setOutlineColor(sf::Color::Black);
	this->_backgroundTitle.setFillColor(sf::Color(110,192,90));

	this->_info.setPosition(x + 5,y + 60);
	this->_info.setSize(sf::Vector2f(390, 50));
	this->_info.setOutlineThickness(1);
	this->_info.setOutlineColor(sf::Color::Black);
	this->_info.setFillColor(sf::Color(159,212,239));

	this->_title.setPosition(x + 15, y + 0);
	this->_title.setCharacterSize(40);
	this->_title.setString("Network");
	this->_title.setFont(*font);
	this->_title.setColor(sf::Color::Black);

	this->_info1.setPosition(x + 10, y + 50 + 15);
	this->_info1.setCharacterSize(22);
	this->_info1.setString(network.getNetwork());
	this->_info1.setFont(*font);
	this->_info1.setColor(sf::Color::Black);

	return;
}

SfmlBlock::~SfmlBlock(void)
{
	return;

}

void		SfmlBlock::affGraph3(Cpu &cpu, sf::RenderWindow *win)
{
	float tmp1;
	float tmp2;
	float tmp3;
	static std::list<float> _userCpu;
	static std::list<float> _userSys;
	static std::list<float> _userIdle;
	int pos = 0;
	int x = 415;

	std::string sTmp1;
	std::string sTmp2;
	std::string sTmp3;

	sTmp1 = strdup(cpu.getCpu());
	pos = sTmp1.find(",", pos);
	sTmp2 = sTmp1.substr(0, pos + 1);
	tmp1 = atoi(&sTmp2[10]);

	pos = sTmp1.find(",", pos);
	tmp2 = atoi(&sTmp1[pos + 2]);
	pos = sTmp1.find(",", pos + 2);
	tmp3 = atoi(&sTmp1[pos + 2]);


	tmp1 = (217 * tmp1) / 100;
	tmp2 = (217 * tmp2) / 100;
	tmp3 = (217 * tmp3) / 100;
	if (_userCpu.size() >= 72)
		_userCpu.pop_front();
	if (_userSys.size() >= 72)
		_userSys.pop_front();
	if (_userIdle.size() >= 72)
		_userIdle.pop_front();

	_userCpu.push_back(tmp1);
	_userSys.push_back(tmp2);
	_userIdle.push_back(tmp3);

	std::list<float>::const_iterator it1 = _userCpu.begin();
	std::list<float>::const_iterator it2 = _userSys.begin();
	std::list<float>::const_iterator it3 = _userIdle.begin();

	std::list<float>::const_iterator it1T = _userCpu.begin();
	std::list<float>::const_iterator it2T = _userSys.begin();
	std::list<float>::const_iterator it3T = _userIdle.begin();

	if (it1T != _userCpu.end())
		it1T++;
	if (it2T != _userSys.end())
		it2T++;
	if (it3T != _userIdle.end())
		it3T++;

	while (it1 != _userCpu.end())
	{
		if (it1T != _userCpu.end())
		{	
			sf::Vertex line1[] =
			{
				sf::Vertex(sf::Vector2f(x, 845 - *it1),sf::Color::Green),
				sf::Vertex(sf::Vector2f(x + 5, 845 - *it1T),sf::Color::Green)
			};
			it1T++;
			win->draw(line1, 2, sf::Lines);
		}
		if (it2T != _userSys.end())
		{	
			sf::Vertex line2[] =
			{
				sf::Vertex(sf::Vector2f(x, 845 - *it2),sf::Color::Blue),
				sf::Vertex(sf::Vector2f(x + 5, 845 - *it2T),sf::Color::Blue)
			};
			it2T++;
			win->draw(line2, 2, sf::Lines);
		}
		if (it3T != _userIdle.end())
		{	
			sf::Vertex line3[] =
			{
				sf::Vertex(sf::Vector2f(x, 845 - *it3),sf::Color::Red),
				sf::Vertex(sf::Vector2f(x + 5, 845 - *it3T),sf::Color::Red)
			};
			it3T++;
			win->draw(line3, 2, sf::Lines);
		}
			x+=5;
			it1++;
			it2++;
			it3++;
		}
	} 

void		SfmlBlock::affGraph2(Ram &ram, sf::RenderWindow *win)
{
	float tmp;
	static std::list<float> _graphList;
	int x = 415;

	tmp = atoi(ram.getPourCentS());
	tmp = (217 * tmp) / 100;
	if (_graphList.size() >= 72)
		_graphList.pop_front();
	_graphList.push_back(tmp);
	std::list<float>::const_iterator it = _graphList.begin();
	std::list<float>::const_iterator itTemp = _graphList.begin();
	if (itTemp != _graphList.end())
		itTemp++;
	while (it != _graphList.end())
	{
		if (itTemp != _graphList.end())
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x, 587 - *it),sf::Color::Black),
				sf::Vertex(sf::Vector2f(x + 5, 587 - *itTemp),sf::Color::Black)
			};
			itTemp++;
			win->draw(line, 2, sf::Lines);
		}
		x+=5;
		it++;
	}
}

void		SfmlBlock::affGraph(Ram &ram, Cpu &cpu, sf::RenderWindow *win, sf::Font *font)
{
	this->_graph.setPosition(400,320);
	this->_graph.setSize(sf::Vector2f(395, 267));
	this->_graph.setOutlineThickness(1);
	this->_graph.setOutlineColor(sf::Color::Black);
	win->draw(this->_graph);

	this->_graphTitle.setPosition(400, 320);
	this->_graphTitle.setSize(sf::Vector2f(395, 50));
	this->_graphTitle.setOutlineThickness(1);
	this->_graphTitle.setOutlineColor(sf::Color::Black);
	this->_graphTitle.setFillColor(sf::Color(123,71,154));
	win->draw(this->_graphTitle);

	this->_titleGraph.setPosition(415, 315);
	this->_titleGraph.setCharacterSize(40);
	this->_titleGraph.setString("System : Memory");
	this->_titleGraph.setFont(*font);
	this->_titleGraph.setColor(sf::Color::Black);
	win->draw(this->_titleGraph);

	this->_graph2.setPosition(400,587);
	this->_graph2.setSize(sf::Vector2f(395, 267));
	this->_graph2.setOutlineThickness(1);
	this->_graph2.setOutlineColor(sf::Color::Black);
	win->draw(this->_graph2);
	this->_titleGraph2.setPosition(415, 587);
	this->_titleGraph2.setCharacterSize(40);
	this->_titleGraph2.setString("System : Processing");
	this->_titleGraph2.setFont(*font);
	this->_titleGraph2.setColor(sf::Color::Black);
	this->_graphTitle2.setPosition(400, 590);
	this->_graphTitle2.setSize(sf::Vector2f(395, 50));
	this->_graphTitle2.setOutlineThickness(1);
	this->_graphTitle2.setOutlineColor(sf::Color::Black);
	this->_graphTitle2.setFillColor(sf::Color(197,55,138));
	win->draw(this->_graphTitle2);
	win->draw(this->_titleGraph2);

	affGraph2(ram, win);
	affGraph3(cpu, win);
}

void		SfmlBlock::affBlock(sf::RenderWindow *win)
{
	win->draw(this->_background);
	win->draw(this->_backgroundTitle);
	win->draw(this->_info);
	win->draw(this->_title);
	win->draw(this->_info1);
	win->draw(this->_info2);
	win->draw(this->_info3);
	win->draw(this->_info4);
	win->draw(this->_info5);
}
