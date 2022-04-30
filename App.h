#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "2Tetronimo.h"
#include "3Tetronimo.h"
#include "4Tetronimo.h"
#include "5Tetronimo.h"
#include "6Tetronimo.h"
#include "7Tetronimo.h"


#include <ctime>


class App {
public:
	App();
	void runApp();
	void runTetris();
	void directions();

private:
	int score = 0;
};