# Makefile

# Compiler

CXX = g++

# Compiler flags

CXXFLAGS = -std=c++11 -Wall -Wextra

# Executable name

TARGET = test_runner

# Source files

SRCS = main.cpp GameBoard.cpp Menu.cpp Button.cpp ActionHandler.cpp Entity.cpp Enemy.cpp Player.cpp EntitySprite.cpp Wizard.cpp Warrior.cpp Ghost.cpp Zombie.cpp CombatLoop.cpp Spell.cpp  

# Build and run tests

.PHONY: all

all:

	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) -I/opt/homebrew/Cellar/sfml/2.5.1_2/include  -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system

	./$(TARGET)

# Clean rule

.PHONY: clean

clean:

	rm -f $(TARGET)