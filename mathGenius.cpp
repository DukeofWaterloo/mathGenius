/*
 * mathGenius.cpp
 *
 *  Created on: Feb. 11, 2021
 *      Author: The Duke of Waterloo
 */

#include <iostream>
#include <time.h>

//TODO: MAYBE ADD GAMELIVES{5}, ADD SUBTRACTION/MULTIPLCATION/DIVISION MODES, FUNCTIONIZE THINGS, LOOK INTO FRACTIONAL ANSWERS FOR DIVISION


//	Difficulty Cap Update keeps the difficulty settings accurate to the current game difficulty
void difficultyCapUpdate(int difficultyIndex,int &difficultyCap, int &difficultySpread, int &responseCap) {
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

	return;
}

//	Difficulty and Mode Selection
void settingInitialization (int &difficultyIndex, int &gameMode) {

	std::string difficultyResponse{""}, modeResponse{""};

	std::cout << "Choose your difficulty: [E]asy, [M]edium, [H]ard, or [G]enius" << std::endl; //E = 5, M = 10, H = 25, G = 100

	std::cin >> difficultyResponse;

	if (difficultyResponse == "e" || difficultyResponse == "E" || difficultyResponse == "Easy" || difficultyResponse == "easy") {
		difficultyIndex = 0;
		std::cout << "Easy difficulty selected, your questions will range from 1 to 5!" << std::endl;
	}

	else if (difficultyResponse == "m" || difficultyResponse == "M" || difficultyResponse == "Medium" || difficultyResponse == "medium") {
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
		std::cout << "Invalid input! Defaulting to easy difficulty." << std::endl;
	}


	std::cout << "Choose your Mode: [A]ddition, [S]ubtraction, [M]ultiplication, or [D]ivision" << std::endl; //A = 0, S = 1, M = 2, D = 3

	std::cin >> modeResponse;
	if (modeResponse == "a" || modeResponse == "A" || modeResponse == "Addition" || modeResponse == "addition") {
		gameMode = 0;
		std::cout << "Addition mode selected, your questions will ask for a sum!" << std::endl;
	}

	else if (modeResponse == "s" || modeResponse == "S" || modeResponse == "Subtraction" || modeResponse == "subtraction") {
		gameMode = 1;
		std::cout << "Subtraction mode selected, your questions will ask for a difference!" << std::endl;
	}

	else if (modeResponse == "m" || modeResponse == "M" || modeResponse == "Multiplication" || modeResponse == "multiplication") {
		gameMode = 2;
		std::cout << "Multiplication mode selected, your questions will ask for a product!" << std::endl;
	}

	else if (modeResponse == "d" || modeResponse == "D" || modeResponse == "Division" || modeResponse == "division") {
		gameMode = 3;
		std::cout << "Division mode selected, your questions will ask for a quotient!" << std::endl;
	}

	else {
		std::cout << "Invalid input! Defaulting to addition mode." << std::endl;
	}
}



//Asks the user a question based on the gameMode and difficulty of the game
void askQuestion(int &questionNumber, int &answer, int &response, int &responseTime, int difficultySpread, int difficultyCap, int gameMode) {
	int number1{0}, number2{0};

	questionNumber++;

	//	Generating a question
	if (gameMode == 0) { //Addition

		number1 = rand()%difficultySpread + difficultyCap;
		number2 = rand()%difficultySpread + difficultyCap;
		answer = number1 + number2;


		std::printf("What is %d + %d? \n", number1, number2);

	}

	else if (gameMode == 1) { //Subtraction

		number1 = rand()%difficultySpread + difficultyCap;
		number2 = rand()%difficultySpread + difficultyCap;
		answer = number1 - number2;


		std::printf("What is %d - %d? \n", number1, number2);
	}

	else if (gameMode == 2) { //Multiplication

		number1 = rand()%difficultySpread + difficultyCap;
		number2 = rand()%difficultySpread + difficultyCap;
		answer = number1 * number2;


		std::printf("What is %d x %d? \n", number1, number2);
	}

	else if (gameMode == 3) { //Division

		number1 = rand()%difficultySpread + difficultyCap;
		number2 = rand()%difficultySpread + difficultyCap;

		while (number1 % number2 != 0) { //Whole number division only
			number2 = rand()%difficultySpread + difficultyCap;
		}

		answer = number1 / number2;


		std::printf("What is %d / %d? \n", number1, number2);
	}


	//	Start Stop to measure responseTime
		time_t start{ time(NULL) };

		std::cin >> response;

		time_t stop{ time(NULL) };

		responseTime = difftime(stop,start);
}


//	Feedback on the Answer (Accuracy and Speed)
void answerFeedback(int response, int answer, int responseTime, int responseCap, int questionNumber, int &correctNumber, int &lastQuestionResult) {
	lastQuestionResult = 0;

	if (response == answer && responseTime <= responseCap) {
		correctNumber++;
		lastQuestionResult = 1;
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
}


int main() {

	int number1{0}, number2{0}, answer{0}, response{0}, questionNumber{0}, correctNumber{0}, difficultyCap{1}, difficultySpread{5}, difficultyIndex{0}, gameActive{1}, responseCap{3}, responseTime{0}, gameMode{0}, lastQuestionResult{0};
	std::string difficultyResponse{""}, continueResponse{""};

	std::cout << "HELLO AND WELCOME TO MATH GENIUS!" << std::endl;

	settingInitialization(difficultyIndex, gameMode);

	difficultyCapUpdate(difficultyIndex, difficultyCap, difficultySpread, responseCap);


	std::cout << "Ready.. set.. GO! \n\n";

	srand(time(0));

	//Game Code to follow
	while (gameActive == 1) {

		askQuestion(questionNumber, answer, response, responseTime, difficultySpread, difficultyCap, gameMode);

		answerFeedback(response, answer, responseTime, responseCap, questionNumber, correctNumber, lastQuestionResult);


//		std::cout << "TOOK YA A GOOD " << difftime(stop,start) << " SECONDS BUD" << std::endl; FEEDBACK CODE


	//	Difficulty Index Update
		if (correctNumber % 25 == 0 && correctNumber != 0 && lastQuestionResult == 1) {
			std::cout <<"So far so good, you've answered " << correctNumber << " questions correct. Moving onto the next difficulty, good luck!" << std::endl;
			difficultyIndex++;
		}

		difficultyCapUpdate(difficultyIndex, difficultyCap, difficultySpread, responseCap);

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

