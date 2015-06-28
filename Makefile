#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/27 10:08:04 by sdurr             #+#    #+#              #
#    Updated: 2015/06/28 18:03:16 by sdurr            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= ft_gkrelm

SRCSFILES	= main.cpp \
			  Info.cpp \
			  Cpu.cpp \
			  Network.cpp \
			  Ram.cpp \
			  Window.class.cpp \
			  Ncurse.cpp \
			  sfml.cpp \
			  Sfml.Block.cpp \
			  IMonitorModule.cpp \
			  IMonitorDisplay.cpp \

SRCPATH = srcs
OBJPATH = obj
CC = clang++
INCLUDES = -I $(SRCPATH) -I $(shell pwd)/SFML/include

LDENV = DYLD_FRAMEWORK_PATH="$(shell pwd)/SFML/Frameworks"

LIBS = -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -framework OpenGl -lncurses

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Compiling all"
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

rmsfml:
	rm -rf SFML
sfml: rmsfml
	curl -O "http://mirror0.sfml-dev.org/files/SFML-2.2-osx-clang-universal.tar.gz"
	mkdir SFML
	tar -xzf SFML-2.2-osx-clang-universal.tar.gz -C SFML --strip-components=1
	mv SFML/extlibs/freetype.framework SFML/Frameworks/
	rm -rf "SFML-2.2-osx-clang-universal.tar.gz"

ldenv:
	@echo export $(LDENV)

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all