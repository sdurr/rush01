/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfml.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acivita <acivita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 07:15:24 by acivita           #+#    #+#             */
/*   Updated: 2015/06/28 17:45:17 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Info.hpp"
#include "Ram.hpp"
#include "Cpu.hpp"
#include "Network.hpp"
#include "Sfml.Block.hpp"


std::string        getInfos(void)
{
	FILE* pipe = popen("top -l 1 -n 0 ", "r");
	if (!pipe) return "ERROR";
	char buffer[128];
	std::string result = "";
	while(!feof(pipe)) {
		if(fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);
	return result;
}

void		sfml(void)
{
	sf::Image Image;
	Image.loadFromFile("Zaz.png");
	sf::Texture texture;
	texture.loadFromImage(Image);
	sf::Sprite sprite;
	sprite.setTexture(texture, true);
	sprite.setPosition(400, 30);
	sprite.scale(0.12, 0.12);

	sf::Image Image2;
	Image2.loadFromFile("logo-1.png");
	sf::Texture texture2;
	texture2.loadFromImage(Image2);
	sf::Sprite sprite2;
	sprite2.setTexture(texture2, true);
	sprite2.setPosition(680, 740);
	sprite2.scale(0.12, 0.12);

	sf::Image Image3;
	Image3.loadFromFile("logo-2.png");
	sf::Texture texture3;
	texture3.loadFromImage(Image3);
	sf::Sprite sprite3;
	sprite3.setTexture(texture3, true);
	sprite3.setPosition(400, 480);
	sprite3.scale(0.25, 0.25);

	Info info;
	Ram ram;
	Cpu cpu;
	Network Net;

	sf::Font font;
	font.loadFromFile("erasdust.ttf");


	sf::RenderWindow app(sf::VideoMode(800, 860, 32), "ft_gkrellm",sf::Style::Titlebar);

	while (app.isOpen())
	{
		sf::Event event;
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				app.close();
			if (sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space)
					return ;
				else if (event.key.code == sf::Keyboard::Escape)
					std::exit(0);
			}
		}
		std::string str = getInfos();
		while (str.size())
		{
			int ps = 0;
			ps = str.find("\n", ps);
			std::string str2 = str.substr(0, ps);
			str.replace(0, ps + 1, "");
			info.setDate();
			ram.setMemUsed(str2);
			Net.setNetwork(str2);
			cpu.setCpu(str2);
		}
	SfmlBlock test(info, &font);
	SfmlBlock test2(ram, &font);
	SfmlBlock test3(cpu, ram, &font);
	SfmlBlock test4(Net, &font);
		app.clear(sf::Color::White);
		test.affBlock(&app);
		test2.affBlock(&app);
		test3.affBlock(&app);
		test4.affBlock(&app);
		app.draw(sprite);
		test2.affGraph(ram, cpu, &app, &font);
		app.draw(sprite2);
		app.draw(sprite3);
		app.display();
	}
}
