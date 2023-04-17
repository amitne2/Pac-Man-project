#include "Ghost.h"
#include "ThePacmanGame.h"

Ghost::Ghost(int _y, int _x)
{
	originalPosition.set(_x, _y);
	position[0] = position[1] = originalPosition;
}

void Ghost:: setGame(ThePacmanGame* _theGame)
{
	theGame = _theGame;
}

void Ghost::setOriginalPosition()
{
	position[0] = position[1] = originalPosition;
}

Point Ghost::getNextPosition()
{
	return position[0];
}

Point Ghost::getCurrentPosition()
{
	return position[1];
}

void Ghost::move(const Point p)
{
	int dir;
	
	dir = rand() % 3;
	position[1] = position[0];
	position[0].move(dir, GHOST);
	
	while (theGame->isWall(position[1].next(dir, GHOST), GHOST))
	{
		position[0] = position[1];
		dir = rand() % 3;
		position[1] = position[0];
		position[0].move(dir, GHOST);
	}


	if (theGame->checkIfTheSamePosition(p, position[0]))
	{
		position[0].draw(' ');
		Sleep(2000);
		if (theGame->isBreadCrumbs(position[1]))
			position[1].draw('.');
		else
			position[1].draw(' ');

		theGame->ghostAtePacman();
	}
	
	//else if() //ghost

	//if (theGame->isGhost())
	//{
	//	//pac.getCurrentPosition().draw(' ');
	//	theGame->updateBoard(position[0]);
	//	Sleep(2000);
	//	ghostAtePacman();
	//}
	/*if (theGame->isFruit(position[1].next(direction)))
			points++;*/

	//setTextColor(color);
	if (theGame->isBreadCrumbs(position[1]))
		position[1].draw('.');
	else
		position[1].draw(' ');
	position[0].draw('$');
}
