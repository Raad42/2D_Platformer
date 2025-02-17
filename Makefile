CC=g++
CXX_FLAGS=-Wall -Wextra
SRCS=Main.cpp \
	Entity.cpp \
	Character.cpp \
	Obstacle.cpp \
	DamagingObstacle.cpp \
	MovingObstacle.cpp \
	Levels.cpp \
	Player.cpp \
	Enemy.cpp \
	GameStats.cpp \
	Game.cpp \
	BoundingBox.cpp \
	PowerUpBlock.cpp \


LINK=-lsfml-graphics -lsfml-window -lsfml-system

build:
	$(CC) $(SRCS) -o game $(LINK)

run: build
	./game
