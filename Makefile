CC=g++
CXX_FLAGS=-Wall -Wextra
SRCS=Main.cpp \
	Entity.cpp \
	Character.cpp \
	Obstacle.cpp \
	DamagingObstacle.cpp \
	Player.cpp \
	Enemy.cpp \
	GameStats.cpp \
	Game.cpp \
	BoundingBox.cpp \
	Levels.cpp


LINK=-lsfml-graphics -lsfml-window -lsfml-system

build:
	$(CC) $(SRCS) -o game $(LINK)

run: build
	./game
