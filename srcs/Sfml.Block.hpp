/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sfml.block.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acivita <acivita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 03:17:25 by acivita           #+#    #+#             */
//   Updated: 2015/06/28 17:37:23 by sdurr            ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef SFML_BLOCK_YO_HPP
# define SFML_BLOCK_YO_HPP

#include <string>
#include "Info.hpp"
#include "Ram.hpp"
#include "Network.hpp"
#include "Cpu.hpp"
#include <list>
#include <SFML/Graphics.hpp>

class		SfmlBlock {


	private:
		SfmlBlock &operator=(SfmlBlock const &rhs);
		SfmlBlock(SfmlBlock const &src);
		SfmlBlock(void);
		SfmlBlock(int nb);

	public:
		~SfmlBlock(void);

		SfmlBlock(Info &info, sf::Font *font);
		SfmlBlock(Ram &ram, sf::Font *font);
		SfmlBlock(Cpu &cpu, Ram &ram, sf::Font *font);
		SfmlBlock(Network &network, sf::Font *font);

		void		affBlock(sf::RenderWindow *win);
		void		affGraph(Ram &ram, Cpu &cpu,sf::RenderWindow *win, sf::Font *font);
		void		affGraph2(Ram &ram, sf::RenderWindow *win);
		void		affGraph3(Cpu &cpu, sf::RenderWindow *win);

		sf::RectangleShape	_background;
		sf::RectangleShape	_backgroundTitle;
		sf::RectangleShape	_info;
		sf::RectangleShape _graph;
		sf::RectangleShape _graph2;
		sf::RectangleShape _graphTitle;
		sf::RectangleShape _graphTitle2;
		sf::Text _titleGraph;
		sf::Text _titleGraph2;
		sf::Text _title;
		sf::Text _info1;
		sf::Text _info2;
		sf::Text _info3;
		sf::Text _info4;
		sf::Text _info5;
};

#endif
