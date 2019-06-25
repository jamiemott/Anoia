#
# Program Name: Final Project: Anoia
# Author:      Jamie Mott
# Date :	May 27, 2019
# Description : This is the makefile for Final Project: Anoia
# Source citation: I looked at several websites to gather information.  I 
# got the most information from the video lecture under the "Make help" tab.
# oregonstate.instructure.com/courses/1719543/pages/make-help?module_item_id=18712386


# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -Wall -std=c++0x

# File variables
OBJS = Main.o Game.o Space.o Airport.o Highway.o House.o Validation.o 
OBJS += Menus.o MovieTheater.o Office.o Olympus.o Player.o Gods.o
SRCS = Main.cpp Game.cpp Space.cpp Airport.cpp Highway.cpp House.cpp
SRCS += Validation.cpp Menus.cpp MovieTheater.cpp Office.cpp Olympus.cpp Player.cpp Gods.cpp
HEADERS = Game.hpp Space.hpp Airport.hpp Highway.hpp House.hpp Validation.hpp 
HEADERS += Menus.hpp MovieTheater.hpp Office.hpp Olympus.hpp Player.hpp Gods.hpp
DOCS = Final_Mott_Jamie_Design.pdf

final: $(OBJS)
	$(CXX) $(CXXFLAGS) -o final $(OBJS)

Main.o: Main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c Main.cpp

Game.o: Game.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c Game.cpp

Player.o: Player.cpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Space.o: Space.cpp Space.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Space.cpp

Airport.o: Airport.cpp Airport.hpp Space.hpp Menus.hpp
	$(CXX) $(CXXFLAGS) -c Airport.cpp

Highway.o: Highway.cpp Highway.hpp Space.hpp Menus.hpp
	$(CXX) $(CXXFLAGS) -c Highway.cpp

House.o: House.cpp House.hpp Space.hpp Menus.hpp
	$(CXX) $(CXXFLAGS) -c House.cpp

MovieTheater.o: MovieTheater.cpp MovieTheater.hpp Space.hpp Menus.hpp
	$(CXX) $(CXXFLAGS) -c MovieTheater.cpp

Office.o: Office.cpp Office.hpp Space.hpp Menus.hpp
	$(CXX) $(CXXFLAGS) -c Office.cpp

Olympus.o: Olympus.cpp Olympus.hpp Space.hpp Menus.hpp Gods.hpp
	$(CXX) $(CXXFLAGS) -c Olympus.cpp

Gods.o: Gods.cpp Gods.hpp Space.hpp Menus.hpp
	$(CXX) $(CXXFLAGS) -c Gods.cpp

Validation.o: Validation.cpp Validation.hpp
	$(CXX) $(CXXFLAGS) -c Validation.cpp

Menus.o: Menus.cpp Menus.hpp Validation.hpp
	$(CXX) $(CXXFLAGS) -c Menus.cpp

clean:
	rm *.o final

#Credit for zip fuction goes to fellow student Michele Costello
zip:
	zip FinalProject_Mott_Jamie.zip $(SRCS) $(HEADERS) $(DOCS) makefile -D