#include "2Tetronimo.h"

//DONE
//The tetronimo that is basically a line:
//****


bool Tetronimos2::moveDown(Square arr[][10]) {
	bool success = false;
	sf::Color bl(50, 50, 50);
	if (x1 == -1) {
		if (arr[0][4].getFillColor() == bl && arr[0][5].getFillColor() == bl && arr[0][6].getFillColor() == bl && arr[0][3].getFillColor() == bl) {
			y1 = 0;
			x1 = 3;
			y2 = 0;
			x2 = 4;
			y3 = 0;
			x3 = 5;
			y4 = 0;
			x4 = 6;
			success = true;
			arr[0][3].setFillColor(color);
			arr[0][4].setFillColor(color);
			arr[0][5].setFillColor(color);
			arr[0][6].setFillColor(color);
		}
	}
	else {
		if (orientation == 0) {
			if (arr[y4 + 1][x4].getFillColor() == bl && arr[y3 + 1][x3].getFillColor() == bl && arr[y2 + 1][x2].getFillColor() == bl && arr[y1 + 1][x1].getFillColor() == bl) {
				down(arr);
				if (y4 != 23) {
					success = true;
				}
			}
		}
		else {
			if (arr[y4 + 1][x4].getFillColor() == bl) {
				down(arr);
				if (y4 != 23) {
					success = true;
				}
			}
		}
	}
	return success;
}


void Tetronimos2::moveLeft(Square arr[][10]) {
	sf::Color bl(50, 50, 50);
	if (orientation == 0) {
		if (x1 == 0) {
			return;
		}
		//Look at squares 1, 2, 4:
		else if (arr[y1][x1 - 1].getFillColor() == bl) {
			left(arr);
		}
	}
	else {
		if (x1 == 0) {
			return;
		}
		//Squares 1, 2:
		else if (arr[y1][x1 - 1].getFillColor() == bl && arr[y2][x2 - 1].getFillColor() == bl && arr[y3][x3 - 1].getFillColor() == bl && arr[y4][x4 - 1].getFillColor() == bl) {
			left(arr);
		}
	}
}

void Tetronimos2::moveRight(Square arr[][10]) {
	sf::Color bl(50, 50, 50);
	if (orientation == 0) {
		if (x4 == 9) {
			return;
		}
		//Look at squares 1, 3, 4:
		else if (arr[y4][x4 + 1].getFillColor() == bl) {
			right(arr);
		}
	}
	else {
		if (x4 == 9) {
			return;
		}
		//Squares 1, 4:
		else if (arr[y1][x1 + 1].getFillColor() == bl && arr[y2][x2 + 1].getFillColor() == bl && arr[y3][x3 + 1].getFillColor() == bl && arr[y4][x4 + 1].getFillColor() == bl) {
			right(arr);
		}
	}
}


void Tetronimos2::turnClockwise(Square arr[][10]) {
	sf::Color bl(50, 50, 50);
	if (orientation == 0) {
		if (arr[y2 + 1][x2].getFillColor() == bl && arr[y2 + 2][x2].getFillColor() == bl && arr[y2 + 3][x2].getFillColor() == bl) {
			arr[y1][x1].setFillColor(bl);
			arr[y2][x2].setFillColor(bl);
			arr[y3][x3].setFillColor(bl);
			arr[y4][x4].setFillColor(bl);
			x1++;
			y2++;
			x3--;
			y3 += 2;
			x4 -= 2;
			y4 += 3;
			arr[y1][x1].setFillColor(color);
			arr[y2][x2].setFillColor(color);
			arr[y3][x3].setFillColor(color);
			arr[y4][x4].setFillColor(color);
			orientation++;
		}
	}
	else {
		if (x1 == 0 || x4 > 7) {
			return;
		}
		if (arr[y1][x1 - 1].getFillColor() == bl && arr[y1][x1 + 1].getFillColor() == bl && arr[y1][x1 + 2].getFillColor() == bl) {
			arr[y1][x1].setFillColor(bl);
			arr[y2][x2].setFillColor(bl);
			arr[y3][x3].setFillColor(bl);
			arr[y4][x4].setFillColor(bl);
			x1--;
			y2--;
			x3++;
			y3 -= 2;
			x4 += 2;
			y4 -= 3;
			arr[y1][x1].setFillColor(color);
			arr[y2][x2].setFillColor(color);
			arr[y3][x3].setFillColor(color);
			arr[y4][x4].setFillColor(color);
			orientation = 0;
		}
	}
}