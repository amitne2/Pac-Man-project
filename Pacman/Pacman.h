#ifndef _PACMAN_H_
#define _PACMAN_H_

#include <cstring>
#include "Game_Object.h"

constexpr char PACMAN_SYMBOL = char(2);

class Pacman : public Game_Object {
private:
	int lives;
	int points;
	char arrowKeys[5];
	void setArrowKeys(const char* keys);

public:
	Pacman();
	void setLives();
	int getPoints() const;
	void setPoints(int _points);
	int getLives() const;
	int getDirection(char key) const;
	void move();
	~Pacman();
};

#endif