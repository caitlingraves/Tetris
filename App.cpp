#include <SFML/Graphics.hpp>
#include "App.h"

//NOT SURE HOW TO DO FONT/TEXT....

App::App() {
	runTetris();
}

void App::runTetris() {
	int score = 0;
	sf::Color bl(50, 50, 50);
	srand(time(NULL));
	Square arr[24][10];
	sf::RenderWindow window(sf::VideoMode(610, 1550), "Tetris!");
	//*****NEED TO GET THIS TO WORK!:
	sf::Text text;
	sf::Font font;
	text.setFont(font);
	text.setCharacterSize(1000);
	text.setFillColor(sf::Color::White);
	text.setOrigin(10, 10);
	text.setString("Hello");
	//
	// 
	// 
	//Sets position for all boxes:
	sf::Event event;
	window.clear();
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j].setPosition((j * 50) + 10 + (10 * j), (i * 50) + 110 + (10 * i));
			window.draw(arr[i][j]);
		}
	}
	//Displays:
	window.draw(text);
	window.display();
	window.clear();
	int choice = 0;
	while (window.isOpen()) {
		//Randomly chooes a tetronimo:
		choice = (rand() % 6) + 1;
		int pos = 500;
		bool success1 = false, success2 = false, success3 = false, success4 = false, runGame = true;
		//Instantiates Tetronimos:
		/////*****NEED FOUR MORE:
		Tetronimo s1;
		Tetronimos2 s2;
		Tetronimos3 s3;
		Tetronimos4 s4;
		Tetronimos5 s5;
		Tetronimos6 s6;
		Tetronimos7 s7;

		///////////////////////
		//Runs until the shape is stopped:
		while (runGame == true) {
			int random = 0;
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			//Right key pressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if (success1 == true) {
					switch (choice) {
					case 1:
						s1.moveRight(arr);
						break;
					case 2:
						s2.moveRight(arr);
						break;
					case 3:
						s3.moveRight(arr);
						break;
					case 4:
						s4.moveRight(arr);
						break;
					case 5:
						s5.moveRight(arr);
						break;
					case 6:
						s6.moveRight(arr);
						break;
					case 7:
						s7.moveRight(arr);
					}
				}
				success1 = false;
			}
			//Left key pressed:
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if (success2 == true) {
					switch (choice) {
					case 1:
						s1.moveLeft(arr);
						break;
					case 2:
						s2.moveLeft(arr);
						break;
					case 3:
						s3.moveLeft(arr);
						break;
					case 4:
						s4.moveLeft(arr);
						break;
					case 5:
						s5.moveLeft(arr);
						break;
					case 6:
						s6.moveLeft(arr);
						break;
					case 7:
						s7.moveLeft(arr);
					}
				}
				success2 = false;
			}
			//Down key pressed:
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (success3 == true) {
					switch (choice) {
					case 1:
						runGame = s1.moveDown(arr);
						break;
					case 2:
						runGame = s2.moveDown(arr);
						break;
					case 3:
						runGame = s3.moveDown(arr);
						break;
					case 4:
						runGame = s4.moveDown(arr);
						break;
					case 5:
						runGame = s5.moveDown(arr);
						break;
					case 6:
						runGame = s6.moveDown(arr);
						break;
					case 7:
						runGame = s7.moveDown(arr);

					}
				}
				success3 = false;
			}
			//Space key pressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (success4 == true) {
 					switch (choice) {
					case 1:
						s1.turnClockwise(arr);
						break;
					case 2:
						s2.turnClockwise(arr);
						break;
					case 3:
						s3.turnClockwise(arr);
						break;
					case 4:
						s4.turnClockwise(arr);
						break;
					case 5:
						s5.turnClockwise(arr);
						break;
					case 6:
						s6.turnClockwise(arr);
						break;
					case 7:
						s7.turnClockwise(arr);
					}
				}
				success4 = false;
			}
			//Doesn't let shape keep on moving after pressed:
			if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
			{
				success1 = true;
			}
			if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
			{
				success2 = true;
			}
			if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
			{
				success3 = true;
			}
			if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
			{
				success4 = true;
			}
			//Moves down after 1000 runs:
			if (pos == 500) {
				switch (choice) {
				case 1:
					runGame = s1.moveDown(arr);
					break;
				case 2:
					runGame = s2.moveDown(arr);
					break;
				case 3:
					runGame = s3.moveDown(arr);
					break;
				case 4:
					runGame = s4.moveDown(arr);
					break;
				case 5:
					runGame = s5.moveDown(arr);
					break;
				case 6:
					runGame = s6.moveDown(arr);
					break;
				case 7:
					runGame = s7.moveDown(arr);

				}
				pos = 0;
			}
			//Draws all boxes:
			for (int i = 0; i < 24; i++) {
				for (int j = 0; j < 10; j++) {
					window.draw(arr[i][j]);
				}
			}
			//Displays:
			window.draw(text);
			window.display();
			window.clear();
			pos++;
		}
		//If 10 blocks in a row:
		int scoreSquares = 0;
		for (int i = 23; i > 0; i--) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j].getFillColor() != bl) {
					scoreSquares++;
				}
			}
			//Adjusts board:
			if (scoreSquares == 10) {
				score += 10;
				for (int k = i; k > 0; k--) {
					for (int l = 0; l < 10; l++) {
						arr[k][l].setFillColor(arr[k - 1][l].getFillColor());
					}
				}
				i = 23;
			}
			scoreSquares = 0;
		}
		//If game is ended, displays score, cout:
		for (int i = 0; i < 10; i++) {
			if (arr[0][i].getFillColor() != bl) {
				std::cout << "Score was: " << score << std::endl;
				system("pause");
				exit(1);
			}
		}
		//Draws the board again after it is adjusted:
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 10; j++) {
				window.draw(arr[i][j]);
			}
		}
		window.draw(text);
		window.display();
		window.clear();
	}
}