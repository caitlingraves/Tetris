#pragma once

#include "Tetromino.h"


class Tetronimos6 : public Tetronimo {
public:
	//Changes with tetromino:
	bool moveDown(Square arr[][10]);
	void moveLeft(Square arr[][10]);
	void moveRight(Square arr[][10]);
	void turnClockwise(Square arr[][10]);
};