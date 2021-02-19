/*
 * mathGenius.cpp
 *
 *  Created on: Feb. 11, 2021
 *      Author: The Duke of Waterloo
 */

#include <iostream>
#include <time.h>

//TODO: ADD GAMELIVES{5}, ADD SUBTRACTION/MULTIPLCATION/DIVISION MODES

int main() {

	int number1{0},number2{0},answer{0},response{0},questionNumber{0},correctNumber{0},difficultyCap{1},difficultySpread{5},difficultyIndex{0},gameActive{1},responseCap{3},responseTime{0};
	std::string difficultyResponse{""}, continueResponse{""};

	std::cout << "HELLO AND WELCOME TO MATH GENIUS!" << std::endl;

//	Difficulty Selection
	std::cout << "Choose your difficulty: [E]asy, [M]edium, [H]ard, or [G]enius" << std::endl; //E = 5, M = 10, H = 25, G = 100

	std::cin >> difficultyResponse;

	if (difficultyResponse == "e" || difficultyResponse == "E" || difficultyResponse == "Easy" || difficultyResponse == "easy") {
		difficultyIndex = 0;
		std::cout << "Easy difficulty selected, your questions will range from 1 to 5!" << std::endl;
	}

	else if (difficultyResponse == "m" || difficultyResponse == "M" || difficultyResponse == "Medium" || difficultyResponse == "Medium") {
		difficultyIndex = 1;
		std::cout << "Medium difficulty selected, your questions will range from 1 to 10!" << std::endl;
	}

	else if (difficultyResponse == "h" || difficultyResponse == "H" || difficultyResponse == "Hard" || difficultyResponse == "hard") {
		difficultyIndex = 2;
		std::cout << "Hard difficulty selected, your questions will range from 5 to 25!" << std::endl;
	}

	else if (difficultyResponse == "g" || difficultyResponse == "G" || difficultyResponse == "Genius" || difficultyResponse == "genius") {
		difficultyIndex = 3;
		std::cout << "Genius difficulty selected, your questions will range from 10 to 100!" << std::endl;
	}

	else {
		std::cout << "Invalid input! Defaulting to easy mode." << std::endl;
	}


//	Difficulty Cap Update MAKE THIS INTO A FUNCITION : CHECK HERE AND AT DIFFICULTY INDEX UPDATE
	if (difficultyIndex == 0) {
		difficultyCap = 1;
		difficultySpread = 5;
		responseCap = 3;
	}

	else if (difficultyIndex == 1) {
		difficultyCap = 1;
		difficultySpread = 10;
		responseCap = 5;
	}

	else if (difficultyIndex == 2) {
		difficultyCap = 5;
		difficultySpread = 20;
		responseCap = 7;
	}

	else if (difficultyIndex == 3) {
		difficultyCap = 10;
		difficultySpread = 90;
		responseCap = 9;
	}


	std::cout << "Ready.. set.. GO!" << std::endl;
	std::cout << std::endl;

	srand(time(0));

	//Game Code to follow
	while (gameActive == 1) {
		questionNumber++;

	//	Generating a question
		number1 = rand()%difficultySpread + difficultyCap;
		number2 = rand()%difficultySpread + difficultyCap;
		answer = number1 + number2;


		std::printf("What is %d + %d? \n", number1, number2);

	//	Start Stop to measure responseTime
		time_t start{ time(NULL) };

		std::cin >> response;

		time_t stop{ time(NULL) };

		responseTime = difftime(stop,start);

		std::cout << "TOOK YA A GOOD " << difftime(stop,start) << " SECONDS BUD" << std::endl;

	//	Feedback on the Answer (Accuracy and Speed)
		if (response == answer && responseTime <= responseCap) {
			correctNumber++;
			std::cout << "Good job, you got this answer right!";
		}

		else if (abs(response - answer) == 1) {
			std::cout << "Sooo closseeee!";
		}

		else if (abs(response - answer) == 1) {
			std::cout << "Sooo closseeee!";
		}

		else if (abs(response - answer) == 2) {
			std::cout << "Almost!";
		}

		else if (abs(response - answer) >= 3) {
			std::cout << "Good try!";
		}

		else if (response == answer && responseTime > responseCap) {
			std::cout << " Right answer but you took too long (" << responseTime << " seconds). Aim for " << responseCap << " seconds or less!" << std::endl;
		}

		std::cout << " You have answered " << correctNumber << " question(s) correct out of " << questionNumber << "." << std::endl;


	//	Difficulty Index Update
		if (correctNumber % 25 == 0 && correctNumber != 0) {
			std::cout <<"So far so good, you've answered " << correctNumber << " questions correct. Moving onto the next difficulty, good luck!" << std::endl;
			difficultyIndex++;
		}


	//	10 Question Checkpoint
		if (questionNumber % 10 == 0) {
			std::cout << "Would you like to keep playing? [Y]es or [N]o?" << std::endl;
			std::cin >> continueResponse;

			if (continueResponse == "y" || continueResponse == "Y" || continueResponse == "Yes" || continueResponse == "yes") {
				gameActive = 1;
			}

			else if (continueResponse == "n" || continueResponse == "N" || continueResponse == "No" || continueResponse == "no") {
				std::cout << "Thank you for playing mathGenius! Your final score is: " << ((correctNumber*100) / questionNumber) << "%" << std::endl;
				gameActive = 0;
			}

			else {
				std::cout << "Invalid entry! Continuing game." << std::endl;
			}
		}

	}

return 0;
}
