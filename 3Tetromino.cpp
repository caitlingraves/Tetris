#include "3Tetronimo.h"

//DONE
//Tetronimo that is a box:
//**
//**

bool Tetronimos3::moveDown(Square arr[][10]) {
	bool success = false;
	sf::Color bl(50, 50, 50);
	if (x1 == -1) {
		if (arr[0][4].getFillColor() == bl && arr[0][5].getFillColor() == bl && arr[1][4].getFillColor() == bl && arr[1][5].getFillColor() == bl) {
			y1 = 0;
			x1 = 4;
			y2 = 0;
			x2 = 5;
			y3 = 1;
			x3 = 4;
			y4 = 1;
			x4 = 5;
			success = true;
			arr[0][4].setFillColor(color);
			arr[0][5].setFillColor(color);
			arr[1][4].setFillColor(color);
			arr[1][5].setFillColor(color);
		}
	}
	else {
		if (arr[y4 + 1][x4].getFillColor() == bl && arr[y3 + 1][x3].getFillColor() == bl) {
			down(arr);
			if (y4 != 23) {
				success = true;
			}
		}
	}
	return success;
}


void Tetronimos3::moveLeft(Square arr[][10]) {
	sf::Color bl(50, 50, 50);
	if (x1 == 0) {
		return;
	}
	//Look at squares 1, 2, 4:
	else if (arr[y1][x1 - 1].getFillColor() == bl && arr[y3][x3 - 1].getFillColor() == bl) {
		left(arr);
	}
}

void Tetronimos3::moveRight(Square arr[][10]) {
	sf::Color bl(50, 50, 50);
	if (x4 == 9) {
		return;
	}
	//Look at squares 1, 2, 4:
	else if (arr[y2][x2 + 1].getFillColor() == bl && arr[y4][x4 + 1].getFillColor() == bl) {
		right(arr);
	}
}


void Tetronimos3::turnClockwise(Square arr[][10]) {
	return;
}